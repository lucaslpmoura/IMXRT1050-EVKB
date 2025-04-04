/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "board.h"
#include "fsl_dmamux.h"
#include "fsl_flexio_i2s_edma.h"
#include "fsl_debug_console.h"

#include "fsl_wm8960.h"
#include "fsl_sai.h"
#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* SAI and I2C instance and clock */
/* SAI and I2C instance and clock */
#define DEMO_CODEC_WM8960
#define DEMO_I2C LPI2C1
#define DEMO_FLEXIO_BASE FLEXIO2
#define DEMO_SAI SAI1
/* Select Audio PLL (786.43 MHz) as sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_SELECT (2U)
/* Clock pre divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER (3U)
/* Clock divider for sai1 clock source */
#define DEMO_SAI1_CLOCK_SOURCE_DIVIDER (31U)
/* Get frequency of sai1 clock */
#define DEMO_SAI_CLK_FREQ                                                            \
    (CLOCK_GetFreq(kCLOCK_AudioPllClk) / (DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER + 1U) / \
     (DEMO_SAI1_CLOCK_SOURCE_DIVIDER + 1U))

/* Select USB1 PLL (480 MHz) as master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_SELECT (0U)
/* Clock divider for master lpi2c clock source */
#define DEMO_LPI2C_CLOCK_SOURCE_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define DEMO_I2C_CLK_FREQ ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (DEMO_LPI2C_CLOCK_SOURCE_DIVIDER + 1U))

/* Select Audio PLL (786.43 MHz) as flexio clock source, need to sync with sai clock, or the codec may not work */
#define DEMO_FLEXIO_CLKSRC_SEL (0U)
/* Clock pre divider for flexio clock source */
#define DEMO_FLEXIO_CLKSRC_PRE_DIV (7U)
/* Clock divider for flexio clock source */
#define DEMO_FLEXIO_CLKSRC_DIV (7U)
#define DEMO_FLEXIO_CLK_FREQ \
    (CLOCK_GetFreq(kCLOCK_AudioPllClk) / (DEMO_FLEXIO_CLKSRC_PRE_DIV + 1U) / (DEMO_FLEXIO_CLKSRC_DIV + 1U))

#define BCLK_PIN (8U)
#define FRAME_SYNC_PIN (7U)
#define TX_DATA_PIN (6U)
#define RX_DATA_PIN (5U)
#define FLEXIO_TX_SHIFTER_INDEX 0
#define FLEXIO_RX_SHIFTER_INDEX 2

#define EXAMPLE_DMAMUX DMAMUX
#define EXAMPLE_DMA DMA0
#define EXAMPLE_TX_CHANNEL 1U
#define EXAMPLE_RX_CHANNEL 0U
#define EXAMPLE_TX_DMA_SOURCE kDmaRequestMuxFlexIO2Request0Request1
#define EXAMPLE_RX_DMA_SOURCE kDmaRequestMuxFlexIO2Request2Request3
#define OVER_SAMPLE_RATE (384)
#define BUFFER_SIZE (128)
#define BUFFER_NUM (2)
#define PLAY_COUNT (5000)
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* USB1 PLL configuration for RUN mode */
const clock_audio_pll_config_t audioPllConfig = {
    .loopDivider = 32U,         /*!< PLL loop divider. Valid range for DIV_SELECT divider value: 27~54. */
    .postDivider = 1U,          /*!< Divider after the PLL, should only be 1, 2, 4, 8, 16. */
    .numerator = 0x05F5E100U,   /*!< 30 bit numerator of fractional loop divider.*/
    .denominator = 0x07C3097FU, /*!< 30 bit denominator of fractional loop divider */
};
AT_NONCACHEABLE_SECTION_INIT(flexio_i2s_edma_handle_t txHandle) = {0};
AT_NONCACHEABLE_SECTION_INIT(flexio_i2s_edma_handle_t rxHandle) = {0};
edma_handle_t txDmaHandle = {0};
edma_handle_t rxDmaHandle = {0};
AT_NONCACHEABLE_SECTION_ALIGN_INIT(static uint8_t audioBuff[BUFFER_SIZE * BUFFER_NUM], 4) = {0};
#if defined(DEMO_CODEC_WM8960)
wm8960_handle_t codecHandle = {0};
#elif defined(DEMO_CODEC_DA7212)
da7212_handle_t codecHandle = {0};
#else
sgtl_handle_t codecHandle = {0};
#endif

#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
lpi2c_master_handle_t i2cHandle = {0};
#else
i2c_master_handle_t i2cHandle = {{0, 0, kI2C_Write, 0, 0, NULL, 0}, 0, 0, NULL, NULL};
#endif
FLEXIO_I2S_Type base;
static volatile bool isTxFinished = false;
static volatile bool isRxFinished = false;
static volatile uint32_t beginCount = 0;
static volatile uint32_t sendCount = 0;
static volatile uint32_t receiveCount = 0;
static volatile uint8_t fullBlock = 0;
static volatile uint8_t emptyBlock = 0;

/*******************************************************************************
 * Code
 ******************************************************************************/
void BOARD_EnableSaiMclkOutput(bool enable)
{
    if (enable)
    {
        IOMUXC_GPR->GPR1 |= IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK;
    }
    else
    {
        IOMUXC_GPR->GPR1 &= (~IOMUXC_GPR_GPR1_SAI1_MCLK_DIR_MASK);
    }
}

static void txCallback(FLEXIO_I2S_Type *i2sBase, flexio_i2s_edma_handle_t *handle, status_t status, void *userData)
{
    sendCount++;
    emptyBlock++;

    if (sendCount == beginCount)
    {
        isTxFinished = true;
    }
}

static void rxCallback(FLEXIO_I2S_Type *i2sBase, flexio_i2s_edma_handle_t *handle, status_t status, void *userData)
{
    receiveCount++;
    fullBlock++;

    if (receiveCount == beginCount)
    {
        isRxFinished = true;
    }
}

/*!
 * @brief Main function
 */
int main(void)
{
    DMAMUX_Type *dmamuxBase = NULL;
    flexio_i2s_config_t config;
    uint32_t sourceClockHz = 0U;
    flexio_i2s_format_t format;
    flexio_i2s_transfer_t txXfer, rxXfer;
    uint8_t txIndex = 0, rxIndex = 0;
    edma_config_t dmaConfig = {0};
#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
    lpi2c_master_config_t i2cConfig = {0};
#else
    i2c_master_config_t i2cConfig = {0};
#endif
    uint32_t i2cSourceClock;

    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_I2C_ConfigurePins();
    BOARD_FLEXIO_ConfigurePins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();
    BOARD_SAI_ConfigurePins();
    CLOCK_InitAudioPll(&audioPllConfig);

    /* Clock setting for LPI2C */
    CLOCK_SetMux(kCLOCK_Lpi2cMux, DEMO_LPI2C_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, DEMO_LPI2C_CLOCK_SOURCE_DIVIDER);
    /* Clock setting for FLEXIO */
    CLOCK_SetMux(kCLOCK_Flexio2Mux, DEMO_FLEXIO_CLKSRC_SEL);
    CLOCK_SetDiv(kCLOCK_Flexio2PreDiv, DEMO_FLEXIO_CLKSRC_PRE_DIV);
    CLOCK_SetDiv(kCLOCK_Flexio2Div, DEMO_FLEXIO_CLKSRC_DIV);
    /* Clock setting for SAI1 */
    CLOCK_SetMux(kCLOCK_Sai1Mux, DEMO_SAI1_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_Sai1PreDiv, DEMO_SAI1_CLOCK_SOURCE_PRE_DIVIDER);
    CLOCK_SetDiv(kCLOCK_Sai1Div, DEMO_SAI1_CLOCK_SOURCE_DIVIDER);
    /* Enable SAI1 MCLK output */
    BOARD_EnableSaiMclkOutput(true);

    PRINTF("FLEXIO I2S EDMA example started!\n\r");

    /* Set flexio i2s pin, shifter and timer */
    base.bclkPinIndex = BCLK_PIN;
    base.fsPinIndex = FRAME_SYNC_PIN;
    base.txPinIndex = TX_DATA_PIN;
    base.rxPinIndex = RX_DATA_PIN;
#if defined FLEXIO_TX_SHIFTER_INDEX
    base.txShifterIndex = FLEXIO_TX_SHIFTER_INDEX;
#else
    base.txShifterIndex = 0;
#endif
#if defined FLEXIO_RX_SHIFTER_INDEX
    base.rxShifterIndex = FLEXIO_RX_SHIFTER_INDEX;
#else
    base.rxShifterIndex = 1;
#endif
    base.bclkTimerIndex = 0;
    base.fsTimerIndex = 1;
    base.flexioBase = DEMO_FLEXIO_BASE;

#if defined(DEMO_CODEC_WM8960) || defined(DEMO_CODEC_DA7212)
    /* Use SAI to do master clock if using WM8960 codec */
    sai_config_t saiConfig;
    /*
     * saiConfig.masterSlave = kSAI_Master;
     * saiConfig.mclkSource = kSAI_MclkSourceSysclk;
     * saiConfig.protocol = kSAI_BusLeftJustified;
     * saiConfig.syncMode = kSAI_ModeAsync;
     * saiConfig.mclkOutputEnable = true;
     */
    SAI_TxGetDefaultConfig(&saiConfig);
    SAI_TxInit(DEMO_SAI, &saiConfig);

    /* Configure the audio format */
    sai_transfer_format_t saiFormat = {0};
    saiFormat.bitWidth = kSAI_WordWidth16bits;
    saiFormat.channel = 0U;
    saiFormat.sampleRate_Hz = kSAI_SampleRate16KHz;
#if defined(FSL_FEATURE_SAI_HAS_MCLKDIV_REGISTER) && (FSL_FEATURE_SAI_HAS_MCLKDIV_REGISTER)
    saiFormat.masterClockHz = OVER_SAMPLE_RATE * saiFormat.sampleRate_Hz;
#else
    saiFormat.masterClockHz = DEMO_SAI_CLK_FREQ;
#endif
    saiFormat.protocol = saiConfig.protocol;

    uint32_t masterClockSrc = DEMO_SAI_CLK_FREQ;
    SAI_TxSetFormat(DEMO_SAI, &saiFormat, masterClockSrc, saiFormat.masterClockHz);
    SAI_TxEnable(DEMO_SAI, true);
#endif
    /* Create EDMA handle */
    /*
     * dmaConfig.enableRoundRobinArbitration = false;
     * dmaConfig.enableHaltOnError = true;
     * dmaConfig.enableContinuousLinkMode = false;
     * dmaConfig.enableDebugMode = false;
     */
    EDMA_GetDefaultConfig(&dmaConfig);
    EDMA_Init(EXAMPLE_DMA, &dmaConfig);
    EDMA_CreateHandle(&txDmaHandle, EXAMPLE_DMA, EXAMPLE_TX_CHANNEL);
    EDMA_CreateHandle(&rxDmaHandle, EXAMPLE_DMA, EXAMPLE_RX_CHANNEL);

#if defined EXAMPLE_DMAMUX
    dmamuxBase = EXAMPLE_DMAMUX;
#else
    dmamuxBase = DMAMUX0;
#endif
    DMAMUX_Init(dmamuxBase);
    DMAMUX_SetSource(dmamuxBase, EXAMPLE_TX_CHANNEL, EXAMPLE_TX_DMA_SOURCE);
    DMAMUX_EnableChannel(dmamuxBase, EXAMPLE_TX_CHANNEL);
    DMAMUX_SetSource(dmamuxBase, EXAMPLE_RX_CHANNEL, EXAMPLE_RX_DMA_SOURCE);
    DMAMUX_EnableChannel(dmamuxBase, EXAMPLE_RX_CHANNEL);

    /* Init SAI module */
    /*
     * config.enableI2S = true;
     */
    FLEXIO_I2S_GetDefaultConfig(&config);
    FLEXIO_I2S_Init(&base, &config);

    /* Configure the audio format */
    format.bitWidth = kFLEXIO_I2S_WordWidth16bits;
    format.sampleRate_Hz = kFLEXIO_I2S_SampleRate16KHz;

    /* Configure Sgtl5000 I2C */
    codecHandle.base = DEMO_I2C;
    codecHandle.i2cHandle = &i2cHandle;
    i2cSourceClock = DEMO_I2C_CLK_FREQ;

#if defined(FSL_FEATURE_SOC_LPI2C_COUNT) && (FSL_FEATURE_SOC_LPI2C_COUNT)
    /*
     * i2cConfig.debugEnable = false;
     * i2cConfig.ignoreAck = false;
     * i2cConfig.pinConfig = kLPI2C_2PinOpenDrain;
     * i2cConfig.baudRate_Hz = 100000U;
     * i2cConfig.busIdleTimeout_ns = 0;
     * i2cConfig.pinLowTimeout_ns = 0;
     * i2cConfig.sdaGlitchFilterWidth_ns = 0;
     * i2cConfig.sclGlitchFilterWidth_ns = 0;
     */
    LPI2C_MasterGetDefaultConfig(&i2cConfig);
    LPI2C_MasterInit(DEMO_I2C, &i2cConfig, i2cSourceClock);
    LPI2C_MasterTransferCreateHandle(DEMO_I2C, &i2cHandle, NULL, NULL);
#else
    /*
     * i2cConfig.baudRate_Bps = 100000U;
     * i2cConfig.enableStopHold = false;
     * i2cConfig.glitchFilterWidth = 0U;
     * i2cConfig.enableMaster = true;
     */
    I2C_MasterGetDefaultConfig(&i2cConfig);
    I2C_MasterInit(DEMO_I2C, &i2cConfig, i2cSourceClock);
#endif

#if defined(DEMO_CODEC_WM8960)
    WM8960_Init(&codecHandle, NULL);
    WM8960_SetProtocol(&codecHandle, kWM8960_BusI2S);
    WM8960_ConfigDataFormat(&codecHandle, OVER_SAMPLE_RATE * format.sampleRate_Hz, format.sampleRate_Hz,
                            format.bitWidth);
#elif defined(DEMO_CODEC_DA7212)
    DA7212_Init(&codecHandle, NULL);
    DA7212_ConfigAudioFormat(&codecHandle, format.sampleRate_Hz, DEMO_SAI_CLK_FREQ, format.bitWidth);
    DA7212_ChangeOutput(&codecHandle, kDA7212_Output_HP);
    DA7212_WriteRegister(&codecHandle, DIALOG7212_DAI_CTRL,
                         (DIALOG7212_DAI_EN_MASK | DIALOG7212_DAI_OE_MASK | DIALOG7212_DAI_WORD_LENGTH_16B |
                          DIALOG7212_DAI_FORMAT_I2S_MODE));
    /* Set the polarity of BCLK */
    DA7212_WriteRegister(&codecHandle, DIALOG7212_DAI_CLK_MODE,
                         DIALOG7212_DAI_BCLKS_PER_WCLK_BCLK64 | DIALOG7212_DAI_CLK_POL_MASK);
#else
    /* configure sgtl5000 */
    sgtl_config_t codecConfig;
    codecConfig.bus = kSGTL_BusI2S;
    codecConfig.master_slave = false;
    codecConfig.route = kSGTL_RoutePlaybackandRecord;
    SGTL_Init(&codecHandle, &codecConfig);
    SGTL_ModifyReg(&codecHandle, CHIP_I2S_CTRL, SGTL5000_I2S_SCLK_INV_CLR_MASK, SGTL5000_I2S_VAILD_FALLING_EDGE);
    /* Configure codec format */
    SGTL_ConfigDataFormat(&codecHandle, OVER_SAMPLE_RATE * format.sampleRate_Hz, format.sampleRate_Hz, format.bitWidth);
#endif

    FLEXIO_I2S_TransferTxCreateHandleEDMA(&base, &txHandle, txCallback, NULL, &txDmaHandle);
    FLEXIO_I2S_TransferRxCreateHandleEDMA(&base, &rxHandle, rxCallback, NULL, &rxDmaHandle);

    sourceClockHz = DEMO_FLEXIO_CLK_FREQ;
    FLEXIO_I2S_TransferSetFormatEDMA(&base, &txHandle, &format, sourceClockHz);
    FLEXIO_I2S_TransferSetFormatEDMA(&base, &rxHandle, &format, sourceClockHz);

    emptyBlock = BUFFER_NUM;
    fullBlock = 1;
    beginCount = PLAY_COUNT;
    txXfer.dataSize = BUFFER_SIZE;
    rxXfer.dataSize = BUFFER_SIZE;

    /* Wait until finished */
    while ((isTxFinished != true) || (isRxFinished != true))
    {
        if ((isTxFinished != true) && (fullBlock > 0))
        {
            txXfer.data = audioBuff + txIndex * BUFFER_SIZE;
            FLEXIO_I2S_TransferSendEDMA(&base, &txHandle, &txXfer);
            fullBlock--;
            txIndex = (txIndex + 1) % BUFFER_NUM;
        }

        if ((isRxFinished != true) && (emptyBlock > 0))
        {
            rxXfer.data = audioBuff + rxIndex * BUFFER_SIZE;
            FLEXIO_I2S_TransferReceiveEDMA(&base, &rxHandle, &rxXfer);
            emptyBlock--;
            rxIndex = (rxIndex + 1) % BUFFER_NUM;
        }
    }

    PRINTF("\n\r FLEXIO I2S EDMA example finished!\n\r ");

    while (1)
    {
    }
}
