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

/*  Standard C Included Files */
#include <stdio.h>
#include <string.h>
#include "board.h"
#include "fsl_debug_console.h"
#include "fsl_lpi2c.h"
#include "fsl_flexio_i2c_master.h"

#include "pin_mux.h"
#include "clock_config.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define BOARD_LPI2C_SLAVE_BASE LPI2C1
#define BOARD_LPI2C_SLAVE_IRQn LPI2C1_IRQn
#define BOARD_FLEXIO_BASE FLEXIO2

/* Select USB1 PLL (480 MHz) as slave lpi2c clock source */
#define LPI2C_CLOCK_SELECT (0U)
/* Clock divider for slave lpi2c clock source */
#define LPI2C_CLOCK_DIVIDER (5U)
/* Get frequency of lpi2c clock */
#define LPI2C_CLOCK_FREQUENCY ((CLOCK_GetFreq(kCLOCK_Usb1PllClk) / 8) / (LPI2C_CLOCK_DIVIDER + 1U))

/* Select USB1 PLL (480 MHz) as flexio clock source */
#define FLEXIO_CLOCK_SELECT (3U)
/* Clock pre divider for flexio clock source */
#define FLEXIO_CLOCK_PRE_DIVIDER (5U)
/* Clock divider for flexio clock source */
#define FLEXIO_CLOCK_DIVIDER (7U)
#define FLEXIO_CLOCK_FREQUENCY \
    (CLOCK_GetFreq(kCLOCK_Usb1PllClk) / (FLEXIO_CLOCK_PRE_DIVIDER + 1U) / (FLEXIO_CLOCK_DIVIDER + 1U))

#define FLEXIO_I2C_SDA_PIN 5U
#define FLEXIO_I2C_SCL_PIN 6U
/* I2C Slave Address */
#define I2C_MASTER_SLAVE_ADDR_7BIT (0x7EU)
/* I2C Baudrate 400K */
#define I2C_BAUDRATE (400000) /* 100K */
/* The length of data */
#define I2C_DATA_LENGTH (13) /* MAX is 256 */

/*******************************************************************************
* Prototypes
*******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

uint8_t g_slave_buff[I2C_DATA_LENGTH];
uint8_t g_master_buff[I2C_DATA_LENGTH];

flexio_i2c_master_handle_t g_m_handle;
FLEXIO_I2C_Type i2cDev;
lpi2c_slave_handle_t g_s_handle;
volatile bool completionFlag = false;

/*******************************************************************************
 * Code
 ******************************************************************************/

static void lpi2c_slave_callback(LPI2C_Type *base, lpi2c_slave_transfer_t *xfer, void *param)
{
    if (xfer->event == kLPI2C_SlaveReceiveEvent)
    {
        xfer->data = g_slave_buff;
        xfer->dataSize = I2C_DATA_LENGTH;
    }

    if (xfer->event == kLPI2C_SlaveCompletionEvent)
    {
        completionFlag = true;
    }
}

int main(void)
{
    lpi2c_slave_config_t slaveConfig;

    flexio_i2c_master_transfer_t masterXfer;
    IRQn_Type flexio_irqs[] = FLEXIO_IRQS;
    uint16_t timeout = UINT16_MAX;

    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /* Clock setting for Lpi2c */
    CLOCK_SetMux(kCLOCK_Lpi2cMux, LPI2C_CLOCK_SELECT);
    CLOCK_SetDiv(kCLOCK_Lpi2cDiv, LPI2C_CLOCK_DIVIDER);
    /* Clock setting for Flexio */
    CLOCK_SetMux(kCLOCK_Flexio2Mux, FLEXIO_CLOCK_SELECT);
    CLOCK_SetDiv(kCLOCK_Flexio2PreDiv, FLEXIO_CLOCK_PRE_DIVIDER);
    CLOCK_SetDiv(kCLOCK_Flexio2Div, FLEXIO_CLOCK_DIVIDER);

    PRINTF("\r\nFlexIO I2C interrupt - LPI2C interrupt\r\n");

    /*  Set i2c slave interrupt priority higher. */
    NVIC_SetPriority(BOARD_LPI2C_SLAVE_IRQn, 0);

    NVIC_SetPriority(flexio_irqs[0], 1);

    /*1.Set up i2c slave first*/
    /*
     * slaveConfig.address0 = 0U;
     * slaveConfig.address1 = 0U;
     * slaveConfig.addressMatchMode = kLPI2C_MatchAddress0;
     * slaveConfig.filterDozeEnable = true;
     * slaveConfig.filterEnable = true;
     * slaveConfig.enableGeneralCall = false;
     * slaveConfig.ignoreAck = false;
     * slaveConfig.enableReceivedAddressRead = false;
     * slaveConfig.sdaGlitchFilterWidth_ns = 0;
     * slaveConfig.sclGlitchFilterWidth_ns = 0;
     * slaveConfig.dataValidDelay_ns = 0;
     * slaveConfig.clockHoldTime_ns = 0;
     */
    LPI2C_SlaveGetDefaultConfig(&slaveConfig);

    slaveConfig.address0 = I2C_MASTER_SLAVE_ADDR_7BIT;

    LPI2C_SlaveInit(BOARD_LPI2C_SLAVE_BASE, &slaveConfig, LPI2C_CLOCK_FREQUENCY);

    for (uint32_t i = 0; i < I2C_DATA_LENGTH; i++)
    {
        g_slave_buff[i] = 0;
    }

    memset(&g_s_handle, 0, sizeof(g_s_handle));

    LPI2C_SlaveTransferCreateHandle(BOARD_LPI2C_SLAVE_BASE, &g_s_handle, lpi2c_slave_callback, NULL);
    LPI2C_SlaveTransferNonBlocking(BOARD_LPI2C_SLAVE_BASE, &g_s_handle, kLPI2C_SlaveCompletionEvent);

    /*2.Set up i2c master to send data to slave*/
    for (uint32_t i = 0; i < I2C_DATA_LENGTH; i++)
    {
        g_master_buff[i] = i;
    }

    PRINTF("Master will send data :");
    for (uint32_t i = 0; i < I2C_DATA_LENGTH; i++)
    {
        if (i % 8 == 0)
        {
            PRINTF("\r\n");
        }
        PRINTF("0x%02X  ", g_master_buff[i]);
    }
    PRINTF("\r\n\r\n");

    flexio_i2c_master_config_t masterConfig;

    /*do hardware configuration*/
    i2cDev.flexioBase = BOARD_FLEXIO_BASE;
    i2cDev.SDAPinIndex = FLEXIO_I2C_SDA_PIN;
    i2cDev.SCLPinIndex = FLEXIO_I2C_SCL_PIN;
    i2cDev.shifterIndex[0] = 0U;
    i2cDev.shifterIndex[1] = 1U;
    i2cDev.timerIndex[0] = 0U;
    i2cDev.timerIndex[1] = 1U;

    /*
     * masterConfig.enableMaster = true;
     * masterConfig.enableInDoze = false;
     * masterConfig.enableInDebug = true;
     * masterConfig.enableFastAccess = false;
     * masterConfig.baudRate_Bps = 100000U;
     */
    FLEXIO_I2C_MasterGetDefaultConfig(&masterConfig);
    masterConfig.baudRate_Bps = I2C_BAUDRATE;
    FLEXIO_I2C_MasterInit(&i2cDev, &masterConfig, FLEXIO_CLOCK_FREQUENCY);

    memset(&g_m_handle, 0, sizeof(g_m_handle));
    memset(&masterXfer, 0, sizeof(masterXfer));

    masterXfer.slaveAddress = I2C_MASTER_SLAVE_ADDR_7BIT;
    masterXfer.direction = kFLEXIO_I2C_Write;
    masterXfer.subaddress = 0;
    masterXfer.subaddressSize = 0;
    masterXfer.data = g_master_buff;
    masterXfer.dataSize = I2C_DATA_LENGTH;

    FLEXIO_I2C_MasterTransferCreateHandle(&i2cDev, &g_m_handle, NULL, NULL);
    FLEXIO_I2C_MasterTransferNonBlocking(&i2cDev, &g_m_handle, &masterXfer);

    /*  wait for transfer completed. */
    while ((!completionFlag) && (timeout--))
    {
    }
    completionFlag = false;

    /* Failed to complete the transfer. */
    if (timeout == 0)
    {
        PRINTF("\r\nTime out ! \r\n");
    }

    /*3.Transfer completed. Check the data.*/
    for (uint32_t i = 0; i < I2C_DATA_LENGTH; i++)
    {
        if (g_slave_buff[i] != g_master_buff[i])
        {
            PRINTF("\r\nError occured in this transfer ! \r\n");
            break;
        }
    }

    PRINTF("Slave received data :");
    for (uint32_t i = 0; i < I2C_DATA_LENGTH; i++)
    {
        if (i % 8 == 0)
        {
            PRINTF("\r\n");
        }
        PRINTF("0x%02X  ", g_slave_buff[i]);
    }
    PRINTF("\r\n\r\n");

    while (1)
    {
    }
}
