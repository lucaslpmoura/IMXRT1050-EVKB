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

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

/* Freescale includes. */
#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "fsl_lpspi.h"
#include "fsl_lpspi_freertos.h"
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

#define EXAMPLE_LPSPI_MASTER_PCS_FOR_INIT (kLPSPI_Pcs0)
#define EXAMPLE_LPSPI_MASTER_PCS_FOR_TRANSFER (kLPSPI_MasterPcs0)

/* Slave related */
#define EXAMPLE_LPSPI_SLAVE_BASEADDR (LPSPI1)
#define EXAMPLE_LPSPI_SLAVE_IRQN (LPSPI1_IRQn)

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

#define SINGLE_BOARD 0
#define BOARD_TO_BOARD 1

#ifndef EXAMPLE_CONNECT_SPI
#define EXAMPLE_CONNECT_SPI SINGLE_BOARD /* Default runs on single board. */
#endif

#if (EXAMPLE_CONNECT_SPI == BOARD_TO_BOARD)
#define isMASTER 0
#define isSLAVE 1
#ifndef SPI_MASTER_SLAVE
#define SPI_MASTER_SLAVE isMASTER
#endif /* SPI_MASTER_SLAVE */
#endif /* EXAMPLE_CONNECT_SPI */

#define TRANSFER_SIZE (512U)        /*! Transfer dataSize.*/
#define TRANSFER_BAUDRATE (500000U) /*! Transfer baudrate - 500k */

/*******************************************************************************
* Prototypes
******************************************************************************/
/* LPSPI user callback */
void LPSPI_SlaveUserCallback(LPSPI_Type *base, lpspi_slave_handle_t *handle, status_t status, void *userData);
extern uint32_t LPSPI_GetInstance(LPSPI_Type *base);

/*******************************************************************************
* Variables
******************************************************************************/
lpspi_slave_handle_t g_s_handle;

uint8_t masterReceiveBuffer[TRANSFER_SIZE] = {0};
uint8_t masterSendBuffer[TRANSFER_SIZE] = {0};
uint8_t slaveReceiveBuffer[TRANSFER_SIZE] = {0};
uint8_t slaveSendBuffer[TRANSFER_SIZE] = {0};

SemaphoreHandle_t lpspi_sem;
/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Task priorities. */
#define slave_task_PRIORITY (configMAX_PRIORITIES - 2)
#define master_task_PRIORITY (configMAX_PRIORITIES - 1)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static void slave_task(void *pvParameters);
#if ((SPI_MASTER_SLAVE == isMaster) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD))
static void master_task(void *pvParameters);
#endif
/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Application entry point.
 */
int main(void)
{
    int i;

    /* Init board hardware. */
    BOARD_ConfigMPU();
    BOARD_InitPins();
    BOARD_BootClockRUN();
    BOARD_InitDebugConsole();

    /*Set clock source for LPSPI*/
    CLOCK_SetMux(kCLOCK_LpspiMux, EXAMPLE_LPSPI_CLOCK_SOURCE_SELECT);
    CLOCK_SetDiv(kCLOCK_LpspiDiv, EXAMPLE_LPSPI_CLOCK_SOURCE_DIVIDER);

    NVIC_SetPriority(EXAMPLE_LPSPI_MASTER_IRQN, 3);
    NVIC_SetPriority(EXAMPLE_LPSPI_SLAVE_IRQN, 2);

    PRINTF("FreeRTOS LPSPI example start.\r\n");
#if (EXAMPLE_CONNECT_SPI == SINGLE_BOARD)
    PRINTF("This example use one lpspi instance as master and another as slave on a single board.\r\n");
#elif(EXAMPLE_CONNECT_SPI == BOARD_TO_BOARD)
    PRINTF("This example use two boards to connect with one as master and anohter as slave.\r\n");
#endif
    PRINTF("Master and slave are both use interrupt way.\r\n");
    PRINTF("Please make sure you make the correct line connection. Basically, the connection is:\r\n");
    PRINTF("LPSPI_master -- LPSPI_slave\r\n");
    PRINTF("    CLK      --    CLK\r\n");
    PRINTF("    PCS      --    PCS\r\n");
    PRINTF("    SOUT     --    SIN\r\n");
    PRINTF("    SIN      --    SOUT\r\n");
    PRINTF("\r\n");

    /* Initialize data in transfer buffers */
    for (i = 0; i < TRANSFER_SIZE; i++)
    {
        masterSendBuffer[i] = i % 256;
        masterReceiveBuffer[i] = 0;

        slaveSendBuffer[i] = ~masterSendBuffer[i];
        slaveReceiveBuffer[i] = 0;
    }

    if (xTaskCreate(slave_task, "Slave_task", configMINIMAL_STACK_SIZE + 64, NULL, slave_task_PRIORITY, NULL) != pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        while (1)
            ;
    }
    vTaskStartScheduler();
    for (;;)
        ;
}

/*!
 * @brief Data structure and callback function for slave SPI communication.
 */

typedef struct _callback_message_t
{
    status_t async_status;
    SemaphoreHandle_t sem;
} callback_message_t;

void LPSPI_SlaveUserCallback(LPSPI_Type *base, lpspi_slave_handle_t *handle, status_t status, void *userData)
{
    callback_message_t *cb_msg = (callback_message_t *)userData;
    BaseType_t reschedule;

    cb_msg->async_status = status;
    xSemaphoreGiveFromISR(cb_msg->sem, &reschedule);
    portYIELD_FROM_ISR(reschedule);
}

/*!
 * @brief Task responsible for slave SPI communication.
 */
static void slave_task(void *pvParameters)
{
#if ((SPI_MASTER_SLAVE == isSLAVE) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD))
    lpspi_slave_config_t slaveConfig;
    lpspi_transfer_t slaveXfer;
#endif
    uint32_t errorCount;
    uint32_t i;
    callback_message_t cb_msg;

    cb_msg.sem = xSemaphoreCreateBinary();
    lpspi_sem = cb_msg.sem;
    if (cb_msg.sem == NULL)
    {
        PRINTF("LPSPI slave: Error creating semaphore\r\n");
        vTaskSuspend(NULL);
    }

#if ((SPI_MASTER_SLAVE == isSLAVE) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD))
    /* Slave config */
    LPSPI_SlaveGetDefaultConfig(&slaveConfig);

    slaveConfig.bitsPerFrame = 8 * TRANSFER_SIZE;
    slaveConfig.cpol = kLPSPI_ClockPolarityActiveHigh;
    slaveConfig.cpha = kLPSPI_ClockPhaseFirstEdge;
    slaveConfig.direction = kLPSPI_MsbFirst;
    slaveConfig.whichPcs = EXAMPLE_LPSPI_SLAVE_PCS_FOR_INIT;
    slaveConfig.pcsActiveHighOrLow = kLPSPI_PcsActiveLow;
    slaveConfig.pinCfg = kLPSPI_SdiInSdoOut;
    slaveConfig.dataOutConfig = kLpspiDataOutRetained;

    LPSPI_SlaveInit(EXAMPLE_LPSPI_SLAVE_BASEADDR, &slaveConfig);

    /*Set up slave first */
    LPSPI_SlaveTransferCreateHandle(EXAMPLE_LPSPI_SLAVE_BASEADDR, &g_s_handle, LPSPI_SlaveUserCallback, &cb_msg);

    /*Set slave transfer ready to receive/send data*/
    slaveXfer.txData = slaveSendBuffer;
    slaveXfer.rxData = slaveReceiveBuffer;
    slaveXfer.dataSize = TRANSFER_SIZE;
    slaveXfer.configFlags = EXAMPLE_LPSPI_SLAVE_PCS_FOR_TRANSFER | kLPSPI_SlaveByteSwap;

    LPSPI_SlaveTransferNonBlocking(EXAMPLE_LPSPI_SLAVE_BASEADDR, &g_s_handle, &slaveXfer);
#endif /* (SPI_MASTER_SLAVE == isSLAVE) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD) */

#if ((SPI_MASTER_SLAVE == isMASTER) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD))
    if (xTaskCreate(master_task, "Master_task", configMINIMAL_STACK_SIZE + 64, NULL, master_task_PRIORITY, NULL) !=
        pdPASS)
    {
        PRINTF("Task creation failed!.\r\n");
        vTaskSuspend(NULL);
    }
#endif /* (SPI_MASTER_SLAVE == isMASTER) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD) */

    /* Wait for transfer to finish */
    xSemaphoreTake(cb_msg.sem, portMAX_DELAY);

#if ((SPI_MASTER_SLAVE == isSLAVE) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD))
    if (cb_msg.async_status == kStatus_Success)
    {
        PRINTF("LPSPI slave transfer completed successfully.\r\n");
    }
    else
    {
        PRINTF("LPSPI slave transfer completed with error.\r\n");
    }
#endif

    errorCount = 0;
    for (i = 0; i < TRANSFER_SIZE; i++)
    {
#if (EXAMPLE_CONNECT_SPI == BOARD_TO_BOARD)
#if (SPI_MASTER_SLAVE == isMASTER)
        if (slaveSendBuffer[i] != masterReceiveBuffer[i])
        {
            errorCount++;
        }
#elif(SPI_MASTER_SLAVE == isSLAVE)
        if (masterSendBuffer[i] != slaveReceiveBuffer[i])
        {
            errorCount++;
        }
#endif
#elif(EXAMPLE_CONNECT_SPI == SINGLE_BOARD)
        if (masterSendBuffer[i] != slaveReceiveBuffer[i])
        {
            errorCount++;
        }

        if (slaveSendBuffer[i] != masterReceiveBuffer[i])
        {
            errorCount++;
        }
#endif
    }

    if (errorCount == 0)
    {
        PRINTF("LPSPI transfer all data matched !\r\n");
    }
    else
    {
        PRINTF("Error occured in LPSPI transfer !\r\n");
    }

    vTaskSuspend(NULL);
}

/*!
 * @brief Task responsible for master SPI communication.
 */
#if ((SPI_MASTER_SLAVE == isMaster) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD))
static void master_task(void *pvParameters)
{
    lpspi_transfer_t masterXfer;
    lpspi_rtos_handle_t master_rtos_handle;
    lpspi_master_config_t masterConfig;
    uint32_t sourceClock;
    status_t status;

    /*
     * masterConfig.bitsPerFrame = 8;
     * masterConfig.cpol = kLPSPI_ClockPolarityActiveHigh;
     * masterConfig.cpha = kLPSPI_ClockPhaseFirstEdge;
     * masterConfig.direction = kLPSPI_MsbFirst;
     * masterConfig.whichPcs = kLPSPI_Pcs0;
     * masterConfig.pcsActiveHighOrLow = kLPSPI_PcsActiveLow;
     * masterConfig.pinCfg = kLPSPI_SdiInSdoOut;
     * masterConfig.dataOutConfig = kLpspiDataOutRetained;
     */
    LPSPI_MasterGetDefaultConfig(&masterConfig);

    masterConfig.baudRate = TRANSFER_BAUDRATE;
    masterConfig.bitsPerFrame = 8 * TRANSFER_SIZE;
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

    sourceClock = EXAMPLE_LPSPI_MASTER_CLOCK_FREQ;

    status = LPSPI_RTOS_Init(&master_rtos_handle, EXAMPLE_LPSPI_MASTER_BASEADDR, &masterConfig, sourceClock);

    if (status != kStatus_Success)
    {
        PRINTF("LPSPI master: error during initialization. \r\n");
        vTaskSuspend(NULL);
    }
    /*Start master transfer*/
    masterXfer.txData = masterSendBuffer;
    masterXfer.rxData = masterReceiveBuffer;
    masterXfer.dataSize = TRANSFER_SIZE;
    masterXfer.configFlags = EXAMPLE_LPSPI_MASTER_PCS_FOR_TRANSFER | kLPSPI_MasterPcsContinuous | kLPSPI_SlaveByteSwap;

    status = LPSPI_RTOS_Transfer(&master_rtos_handle, &masterXfer);

    if (status == kStatus_Success)
    {
#if (EXAMPLE_CONNECT_SPI == BOARD_TO_BOARD)
        xSemaphoreGive(lpspi_sem);
#endif
        PRINTF("LPSPI master transfer completed successfully.\r\n");
    }
    else
    {
        PRINTF("LPSPI master transfer completed with error.\r\n");
    }

    vTaskSuspend(NULL);
}
#endif //((SPI_MASTER_SLAVE == isMaster) || (EXAMPLE_CONNECT_SPI == SINGLE_BOARD))
