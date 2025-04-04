/*
 * Copyright (c) 2013 - 2015, Freescale Semiconductor, Inc.
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

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_lpspi.h"
#include "board.h"

#include "fsl_common.h"
#include "pin_mux.h"
#if ((defined FSL_FEATURE_SOC_INTMUX_COUNT) && (FSL_FEATURE_SOC_INTMUX_COUNT))
#include "fsl_intmux.h"
#endif
/*******************************************************************************
* Definitions
******************************************************************************/
/* Master related */
#define EXAMPLE_LPSPI_MASTER_BASEADDR (LPSPI3)
#define EXAMPLE_LPSPI_MASTER_IRQN (LPSPI3_IRQn)
#define EXAMPLE_LPSPI_MASTER_IRQHandler (LPSPI3_IRQHandler)

#define EXAMPLE_LPSPI_MASTER_PCS_FOR_INIT (kLPSPI_Pcs0)
#define EXAMPLE_LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs0)

/* Slave related */
#define EXAMPLE_LPSPI_SLAVE_BASEADDR (LPSPI1)
#define EXAMPLE_LPSPI_SLAVE_IRQN (LPSPI1_IRQn)
#define EXAMPLE_LPSPI_SLAVE_IRQHandler (LPSPI1_IRQHandler)

#define EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT (kLPSPI_Pcs0)
#define EXAMPLE_LPSPI_SLAVE_PCS_FOR_TRANSFER (kLPSPI_SlavePcs0)

/* Select USB1 PLL PFD0 (720 MHz) as lpspi clock source */
#define EXAMPLE_LPSPI_CLOCK_SOURCE_SELECT (1U)
/* Clock divider for master lpspi clock source */
#define EXAMPLE_LPSPI_CLOCK_SOURCE_DIVIDER (7U)

#define EXAMPLE_LPSPI_CLOCK_FREQ \
    (CLOCK_GetFreq(kCLOCK_Usb1PllPfd0Clk) / (EXAMPLE_LPSPI_CLOCK_SOURCE_DIVIDER + 1U))

#define EXAMPLE_LPSPI_MASTER_CLOCK_FREQ EXAMPLE_LPSPI_CLOCK_FREQ
#define EXAMPLE_LPSPI_SLAVE_CLOCK_FREQ EXAMPLE_LPSPI_CLOCK_FREQ

#define TRANSFER_SIZE (512U)        /*! Transfer dataSize .*/
#define TRANSFER_BAUDRATE (500000U) /*! Transfer baudrate - 500k */

/*******************************************************************************
* Prototypes
******************************************************************************/
/* LPSPI user callback */
void LPSPI_SlaveUserCallback(LPSPI_Type *base, lpspi_slave_handle_t *handle, status_t status, void *userData);
void LPSPI_MasterUserCallback(LPSPI_Type *base, lpspi_master_handle_t *handle, status_t status, void *userData);

/*******************************************************************************
* Variables
******************************************************************************/
uint8_t masterRxData[TRANSFER_SIZE] = {0};
uint8_t masterTxData[TRANSFER_SIZE] = {0};
uint8_t slaveRxData[TRANSFER_SIZE] = {0};
uint8_t slaveTxData[TRANSFER_SIZE] = {0};

volatile uint32_t slaveTxCount;
volatile uint32_t slaveRxCount;
uint8_t g_slaveRxWatermark;
uint8_t g_slaveFifoSize;

volatile uint32_t masterTxCount;
volatile uint32_t masterRxCount;
uint8_t g_masterRxWatermark;
uint8_t g_masterFifoSize;

volatile bool isSlaveTransferCompleted = false;
volatile bool isMasterTransferCompleted = false;

/*******************************************************************************
* Code
******************************************************************************/
void LPSPI_SlaveUserCallback(LPSPI_Type *base, lpspi_slave_handle_t *handle, status_t status, void *userData)
{
    if (status == kStatus_Success)
    {
        PRINTF("This is LPSPI slave transfer completed callback. \r\n");
        PRINTF("It's a successful transfer. \r\n\r\n");
    }
    else if (status == kStatus_LPSPI_Error)
    {
        PRINTF("This is LPSPI slave transfer completed callback. \r\n");
        PRINTF("Error occured in this transfer. \r\n\r\n");
    }
    else
    {
        __NOP();
    }

    isSlaveTransferCompleted = true;
}

void LPSPI_MasterUserCallback(LPSPI_Type *base, lpspi_master_handle_t *handle, status_t status, void *userData)
{
    isMasterTransferCompleted = true;
}

void EXAMPLE_LPSPI_SLAVE_IRQHandler(void)
{
    if (slaveRxCount < TRANSFER_SIZE)
    {
        while (LPSPI_GetRxFifoCount(EXAMPLE_LPSPI_SLAVE_BASEADDR))
        {
            slaveRxData[slaveRxCount] = LPSPI_ReadData(EXAMPLE_LPSPI_SLAVE_BASEADDR);
            slaveRxCount++;

            if (slaveTxCount < TRANSFER_SIZE)
            {
                LPSPI_WriteData(EXAMPLE_LPSPI_SLAVE_BASEADDR, slaveTxData[slaveTxCount]);
                slaveTxCount++;
            }
            if (slaveRxCount == TRANSFER_SIZE)
            {
                break;
            }
        }
    }

    /*Update rxWatermark. There isn't RX interrupt for the last datas if the RX count is not greater than rxWatermark.*/
    if ((TRANSFER_SIZE - slaveRxCount) <= g_slaveRxWatermark)
    {
        EXAMPLE_LPSPI_SLAVE_BASEADDR->FCR =
            (EXAMPLE_LPSPI_SLAVE_BASEADDR->FCR & (~LPSPI_FCR_RXWATER_MASK)) |
            LPSPI_FCR_RXWATER(((TRANSFER_SIZE - slaveRxCount) > 1) ? ((TRANSFER_SIZE - slaveRxCount) - 1U) : (0U));
    }

    /* Check if remaining receive byte count matches user request */
    if ((slaveRxCount == TRANSFER_SIZE) && (slaveTxCount == TRANSFER_SIZE))
    {
        isSlaveTransferCompleted = true;
        /* Disable interrupt requests */
        LPSPI_DisableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_RxInterruptEnable);
    }
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
      exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

void EXAMPLE_LPSPI_MASTER_IRQHandler(void)
{
    if (masterRxCount < TRANSFER_SIZE)
    {
        /* First, disable the interrupts to avoid potentially triggering another interrupt
        * while reading out the RX FIFO as more data may be coming into the RX FIFO. We'll
        * re-enable the interrupts EXAMPLE_LPSPI_MASTER_BASEADDRd on the LPSPI state after reading out the FIFO.
        */
        LPSPI_DisableInterrupts(EXAMPLE_LPSPI_MASTER_BASEADDR, kLPSPI_RxInterruptEnable);

        while (LPSPI_GetRxFifoCount(EXAMPLE_LPSPI_MASTER_BASEADDR))
        {
            /*Read out the data*/
            masterRxData[masterRxCount] = LPSPI_ReadData(EXAMPLE_LPSPI_MASTER_BASEADDR);

            masterRxCount++;

            if (masterRxCount == TRANSFER_SIZE)
            {
                break;
            }
        }

        /* Re-enable the interrupts only if rxCount indicates there is more data to receive,
        * else we may get a spurious interrupt.
        * */
        if (masterRxCount < TRANSFER_SIZE)
        {
            /* Set the TDF and RDF interrupt enables simultaneously to avoid race conditions */
            LPSPI_EnableInterrupts(EXAMPLE_LPSPI_MASTER_BASEADDR, kLPSPI_RxInterruptEnable);
        }
    }

    /*Update rxWatermark. There isn't RX interrupt for the last datas if the RX count is not greater than rxWatermark.*/
    if ((TRANSFER_SIZE - masterRxCount) <= g_masterRxWatermark)
    {
        EXAMPLE_LPSPI_MASTER_BASEADDR->FCR =
            (EXAMPLE_LPSPI_MASTER_BASEADDR->FCR & (~LPSPI_FCR_RXWATER_MASK)) |
            LPSPI_FCR_RXWATER(((TRANSFER_SIZE - masterRxCount) > 1) ? ((TRANSFER_SIZE - masterRxCount) - 1U) : (0U));
    }

    if (masterTxCount < TRANSFER_SIZE)
    {
        while ((LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_MASTER_BASEADDR) < g_masterFifoSize) &&
               (masterTxCount - masterRxCount < g_masterFifoSize))
        {
            /*Write the word to TX register*/
            LPSPI_WriteData(EXAMPLE_LPSPI_MASTER_BASEADDR, masterTxData[masterTxCount]);
            ++masterTxCount;

            if (masterTxCount == TRANSFER_SIZE)
            {
                break;
            }
        }
    }

    /* Check if we're done with this transfer.*/
    if ((masterTxCount == TRANSFER_SIZE) && (masterRxCount == TRANSFER_SIZE))
    {
        isMasterTransferCompleted = true;
        /* Complete the transfer and disable the interrupts */
        LPSPI_DisableInterrupts(EXAMPLE_LPSPI_MASTER_BASEADDR, kLPSPI_AllInterruptEnable);
    }
    /* Add for ARM errata 838869, affects Cortex-M4, Cortex-M4F Store immediate overlapping
      exception return operation might vector to incorrect interrupt */
#if defined __CORTEX_M && (__CORTEX_M == 4U)
    __DSB();
#endif
}

/*!
* @brief Main function
*/
int main(void)
{
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /*Set clock source for LPSPI*/
    CLOCK_SetMux(kCLOCK_LpspiMux, EXAMPLE_LPSPI_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_LpspiDiv, EXAMPLE_LPSPI_CLOCK_SOURCE_DIVIDER);


    PRINTF("LPSPI functional interrupt example start.\r\n");
    PRINTF("This example use one lpspi instance as master and another as slave on one board.\r\n");
    PRINTF("Master uses interrupt way and slave uses interrupt way.\r\n");
    PRINTF(
        "Note that some LPSPI instances interrupt is in INTMUX ,"
        "you should set the intmux when you porting this example accordingly \r\n");

    PRINTF("Please make sure you make the correct line connection. Basically, the connection is: \r\n");
    PRINTF("LPSPI_master -- LPSPI_slave   \r\n");
    PRINTF("   CLK      --    CLK  \r\n");
    PRINTF("   PCS      --    PCS \r\n");
    PRINTF("   SOUT     --    SIN  \r\n");
    PRINTF("   SIN      --    SOUT \r\n");

    uint32_t errorCount;
    uint32_t i;
    lpspi_master_config_t masterConfig;
    lpspi_slave_config_t slaveConfig;
    uint32_t whichPcs;
    uint8_t txWatermark;

    /*Set up the transfer data*/
    for (i = 0; i < TRANSFER_SIZE; i++)
    {
        masterTxData[i] = i % 256;
        masterRxData[i] = 0;

        slaveTxData[i] = ~masterTxData[i];
        slaveRxData[i] = 0;
    }

    /*Master config*/
    masterConfig.baudRate = TRANSFER_BAUDRATE;
    masterConfig.bitsPerFrame = 8;
    masterConfig.cpol = kLPSPI_ClockPolarityActiveHigh;
    masterConfig.cpha = kLPSPI_ClockPhaseFirstEdge;
    masterConfig.direction = kLPSPI_MsbFirst;

    masterConfig.pcsToSckDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    masterConfig.lastSckToPcsDelayInNanoSec = 1000000000 / masterConfig.baudRate;
    masterConfig.betweenTransferDelayInNanoSec = 1000000000 / masterConfig.baudRate;

    masterConfig.whichPcs = EXAMPLE_LPSPI_MASTER_PCS_FOR_INIT;
    masterConfig.pcsActiveHighOrLow = kLPSPI_PcsActiveLow;

    masterConfig.pinCfg = kLPSPI_SdiInSdoOut;
    masterConfig.dataOutConfig = kLpspiDataOutRetained;

    LPSPI_MasterInit(EXAMPLE_LPSPI_MASTER_BASEADDR, &masterConfig, EXAMPLE_LPSPI_MASTER_CLOCK_FREQ);

    /*Slave config*/
    slaveConfig.bitsPerFrame = masterConfig.bitsPerFrame;
    slaveConfig.cpol = masterConfig.cpol;
    slaveConfig.cpha = masterConfig.cpha;
    slaveConfig.direction = masterConfig.direction;

    slaveConfig.whichPcs = EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT;
    slaveConfig.pcsActiveHighOrLow = masterConfig.pcsActiveHighOrLow;

    slaveConfig.pinCfg = kLPSPI_SdiInSdoOut;
    slaveConfig.dataOutConfig = kLpspiDataOutRetained;

    LPSPI_SlaveInit(EXAMPLE_LPSPI_SLAVE_BASEADDR, &slaveConfig);

    /******************Set up slave first ******************/
    isSlaveTransferCompleted = false;
    slaveTxCount = 0;
    slaveRxCount = 0;
    whichPcs = EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT;

    /*The TX and RX FIFO sizes are always the same*/
    g_slaveFifoSize = LPSPI_GetRxFifoSize(EXAMPLE_LPSPI_SLAVE_BASEADDR);

    /*Set the RX and TX watermarks to reduce the ISR times.*/
    if (g_slaveFifoSize > 1)
    {
        txWatermark = 1;
        g_slaveRxWatermark = g_slaveFifoSize - 2;
    }
    else
    {
        txWatermark = 0;
        g_slaveRxWatermark = 0;
    }

    LPSPI_SetFifoWatermarks(EXAMPLE_LPSPI_SLAVE_BASEADDR, txWatermark, g_slaveRxWatermark);

    LPSPI_Enable(EXAMPLE_LPSPI_SLAVE_BASEADDR, false);
    EXAMPLE_LPSPI_SLAVE_BASEADDR->CFGR1 &= (~LPSPI_CFGR1_NOSTALL_MASK);
    LPSPI_Enable(EXAMPLE_LPSPI_SLAVE_BASEADDR, true);

    /*Flush FIFO , clear status , disable all the interrupts.*/
    LPSPI_FlushFifo(EXAMPLE_LPSPI_SLAVE_BASEADDR, true, true);
    LPSPI_ClearStatusFlags(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_AllStatusFlag);
    LPSPI_DisableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_AllInterruptEnable);

    EXAMPLE_LPSPI_SLAVE_BASEADDR->TCR =
        (EXAMPLE_LPSPI_SLAVE_BASEADDR->TCR &
         ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK | LPSPI_TCR_RXMSK_MASK | LPSPI_TCR_PCS_MASK)) |
        LPSPI_TCR_CONT(0) | LPSPI_TCR_CONTC(0) | LPSPI_TCR_RXMSK(0) | LPSPI_TCR_TXMSK(0) | LPSPI_TCR_PCS(whichPcs);

    /* Enable the NVIC for LPSPI peripheral. Note that below code is useless if the LPSPI interrupt is in INTMUX ,
    * and you should also enable the INTMUX interrupt in your application.
    */
    EnableIRQ(EXAMPLE_LPSPI_SLAVE_IRQN);

    /*TCR is also shared the FIFO , so wait for TCR written.*/
    while (LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_SLAVE_BASEADDR) != 0)
    {
    }
    /*Fill up the TX data in FIFO */
    while (LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_SLAVE_BASEADDR) < g_slaveFifoSize)
    {
        /*Write the word to TX register*/
        LPSPI_WriteData(EXAMPLE_LPSPI_SLAVE_BASEADDR, slaveTxData[slaveTxCount]);
        ++slaveTxCount;

        if (slaveTxCount == TRANSFER_SIZE)
        {
            break;
        }
    }
    LPSPI_EnableInterrupts(EXAMPLE_LPSPI_SLAVE_BASEADDR, kLPSPI_RxInterruptEnable);

    /******************Set up master transfer******************/
    isMasterTransferCompleted = false;
    masterTxCount = 0;
    masterRxCount = 0;
    whichPcs = EXAMPLE_LPSPI_MASTER_PCS_FOR_INIT;

    /*The TX and RX FIFO sizes are always the same*/
    g_masterFifoSize = LPSPI_GetRxFifoSize(EXAMPLE_LPSPI_MASTER_BASEADDR);

    /*Set the RX and TX watermarks to reduce the ISR times.*/
    if (g_masterFifoSize > 1)
    {
        txWatermark = 1;
        g_masterRxWatermark = g_masterFifoSize - 2;
    }
    else
    {
        txWatermark = 0;
        g_masterRxWatermark = 0;
    }

    LPSPI_SetFifoWatermarks(EXAMPLE_LPSPI_MASTER_BASEADDR, txWatermark, g_masterRxWatermark);

    LPSPI_Enable(EXAMPLE_LPSPI_MASTER_BASEADDR, false);
    EXAMPLE_LPSPI_MASTER_BASEADDR->CFGR1 &= (~LPSPI_CFGR1_NOSTALL_MASK);
    LPSPI_Enable(EXAMPLE_LPSPI_MASTER_BASEADDR, true);

    /*Flush FIFO , clear status , disable all the inerrupts.*/
    LPSPI_FlushFifo(EXAMPLE_LPSPI_MASTER_BASEADDR, true, true);
    LPSPI_ClearStatusFlags(EXAMPLE_LPSPI_MASTER_BASEADDR, kLPSPI_AllStatusFlag);
    LPSPI_DisableInterrupts(EXAMPLE_LPSPI_MASTER_BASEADDR, kLPSPI_AllInterruptEnable);

    EXAMPLE_LPSPI_MASTER_BASEADDR->TCR =
        (EXAMPLE_LPSPI_MASTER_BASEADDR->TCR &
         ~(LPSPI_TCR_CONT_MASK | LPSPI_TCR_CONTC_MASK | LPSPI_TCR_RXMSK_MASK | LPSPI_TCR_PCS_MASK)) |
        LPSPI_TCR_CONT(0) | LPSPI_TCR_CONTC(0) | LPSPI_TCR_RXMSK(0) | LPSPI_TCR_TXMSK(0) | LPSPI_TCR_PCS(whichPcs);

    /* Enable the NVIC for LPSPI peripheral. Note that below code is useless if the LPSPI interrupt is in INTMUX ,
    * and you should also enable the INTMUX interupt in your application.
    */
    EnableIRQ(EXAMPLE_LPSPI_MASTER_IRQN);

    /*TCR is also shared the FIFO , so wait for TCR written.*/
    while (LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_MASTER_BASEADDR) != 0)
    {
    }
    /*Fill up the TX data in FIFO */
    while ((LPSPI_GetTxFifoCount(EXAMPLE_LPSPI_MASTER_BASEADDR) < g_masterFifoSize) &&
           (masterTxCount - masterRxCount < g_masterFifoSize))
    {
        /*Write the word to TX register*/
        LPSPI_WriteData(EXAMPLE_LPSPI_MASTER_BASEADDR, masterTxData[masterTxCount]);
        ++masterTxCount;

        if (masterTxCount == TRANSFER_SIZE)
        {
            break;
        }
    }
    LPSPI_EnableInterrupts(EXAMPLE_LPSPI_MASTER_BASEADDR, kLPSPI_RxInterruptEnable);

    /******************Wait for master and slave transfer completed.******************/
    while ((!isSlaveTransferCompleted) || (!isMasterTransferCompleted))
    {
    }

    errorCount = 0;
    for (i = 0; i < TRANSFER_SIZE; i++)
    {
        if (masterTxData[i] != slaveRxData[i])
        {
            errorCount++;
        }

        if (slaveTxData[i] != masterRxData[i])
        {
            errorCount++;
        }
    }
    if (errorCount == 0)
    {
        PRINTF("\r\nLPSPI transfer all data matched! \r\n");
    }
    else
    {
        PRINTF("\r\nError occurred in LPSPI transfer ! \r\n");
    }

    LPSPI_Deinit(EXAMPLE_LPSPI_MASTER_BASEADDR);
    LPSPI_Deinit(EXAMPLE_LPSPI_SLAVE_BASEADDR);

    PRINTF("End of example. \r\n");

    while (1)
    {
    }
}
