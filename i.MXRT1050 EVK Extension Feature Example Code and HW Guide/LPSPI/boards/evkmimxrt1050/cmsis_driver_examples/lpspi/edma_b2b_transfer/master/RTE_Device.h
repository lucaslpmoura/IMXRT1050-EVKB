/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
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

#ifndef __RTE_DEVICE_H
#define __RTE_DEVICE_H

/*Driver name mapping.*/
#define RTE_SPI1 0
#define RTE_SPI1_DMA_EN 0
#define RTE_SPI2 0
#define RTE_SPI2_DMA_EN 0
#define RTE_SPI3 1
#define RTE_SPI3_DMA_EN 1
#define RTE_SPI4 0
#define RTE_SPI4_DMA_EN 0

/* SPI configuration. */
#define RTE_SPI1_PCS_TO_SCK_DELAY 1000
#define RTE_SPI1_SCK_TO_PSC_DELAY 1000
#define RTE_SPI1_BETWEEN_TRANSFER_DELAY 1000
#define RTE_SPI1_MASTER_PCS_PIN_SEL (kLPSPI_MasterPcs0)
#define RTE_SPI1_SLAVE_PCS_PIN_SEL (kLPSPI_SlavePcs0)
#define RTE_SPI1_DMA_TX_CH 0
#define RTE_SPI1_DMA_TX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI1Tx
#define RTE_SPI1_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_SPI1_DMA_TX_DMA_BASE DMA0
#define RTE_SPI1_DMA_RX_CH 1
#define RTE_SPI1_DMA_RX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI1Rx
#define RTE_SPI1_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_SPI1_DMA_RX_DMA_BASE DMA0

#define RTE_SPI2_PCS_TO_SCK_DELAY 1000
#define RTE_SPI2_SCK_TO_PSC_DELAY 1000
#define RTE_SPI2_BETWEEN_TRANSFER_DELAY 1000
#define RTE_SPI2_MASTER_PCS_PIN_SEL (kLPSPI_MasterPcs0)
#define RTE_SPI2_SLAVE_PCS_PIN_SEL (kLPSPI_SlavePcs0)
#define RTE_SPI2_DMA_TX_CH 2
#define RTE_SPI2_DMA_TX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI2Tx
#define RTE_SPI2_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_SPI2_DMA_TX_DMA_BASE DMA0
#define RTE_SPI2_DMA_RX_CH 3
#define RTE_SPI2_DMA_RX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI2Tx
#define RTE_SPI2_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_SPI2_DMA_RX_DMA_BASE DMA0

#define RTE_SPI3_PCS_TO_SCK_DELAY 1000
#define RTE_SPI3_SCK_TO_PSC_DELAY 1000
#define RTE_SPI3_BETWEEN_TRANSFER_DELAY 1000
#define RTE_SPI3_MASTER_PCS_PIN_SEL (kLPSPI_MasterPcs0)
#define RTE_SPI3_SLAVE_PCS_PIN_SEL (kLPSPI_SlavePcs0)
#define RTE_SPI3_DMA_TX_CH 4
#define RTE_SPI3_DMA_TX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI3Tx
#define RTE_SPI3_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_SPI3_DMA_TX_DMA_BASE DMA0
#define RTE_SPI3_DMA_RX_CH 5
#define RTE_SPI3_DMA_RX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI3Rx
#define RTE_SPI3_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_SPI3_DMA_RX_DMA_BASE DMA0

#define RTE_SPI4_PCS_TO_SCK_DELAY 1000
#define RTE_SPI4_SCK_TO_PSC_DELAY 1000
#define RTE_SPI4_BETWEEN_TRANSFER_DELAY 1000
#define RTE_SPI4_MASTER_PCS_PIN_SEL (kLPSPI_MasterPcs0)
#define RTE_SPI4_SLAVE_PCS_PIN_SEL (kLPSPI_SlavePcs0)
#define RTE_SPI4_DMA_TX_CH 6
#define RTE_SPI4_DMA_TX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI4Tx
#define RTE_SPI4_DMA_TX_DMAMUX_BASE DMAMUX
#define RTE_SPI4_DMA_TX_DMA_BASE DMA0
#define RTE_SPI4_DMA_RX_CH 7
#define RTE_SPI4_DMA_RX_PERI_SEL (uint8_t) kDmaRequestMuxLPSPI4Rx
#define RTE_SPI4_DMA_RX_DMAMUX_BASE DMAMUX
#define RTE_SPI4_DMA_RX_DMA_BASE DMA0

#endif /* __RTE_DEVICE_H */
