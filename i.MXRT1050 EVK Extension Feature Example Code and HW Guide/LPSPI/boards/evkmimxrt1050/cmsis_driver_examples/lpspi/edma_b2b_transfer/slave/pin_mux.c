/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
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
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
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

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v3.0
processor: MIMXRT1052xxx6A
package_id: MIMXRT1052DVL6A
mcu_data: i_mx_1_0
processor_version: 0.0.1
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void BOARD_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);          /* iomuxc clock (iomuxc_clk_enable): 0x03u */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_12_LPUART1_TX,        /* GPIO_AD_B0_12 is configured as LPUART1_TX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_13_LPUART1_RX,        /* GPIO_AD_B0_13 is configured as LPUART1_RX */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_12_LPUART1_TX,        /* GPIO_AD_B0_12 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_13_LPUART1_RX,        /* GPIO_AD_B0_13 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
LPSPI3_InitPins:
- options: {coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: G11, peripheral: LPSPI3, signal: PCS0, pin_signal: GPIO_AD_B0_03, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100,
    drive_strength: R0_6, pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: M14, peripheral: LPSPI3, signal: SCK, pin_signal: GPIO_AD_B0_00, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: M11, peripheral: LPSPI3, signal: SDI, pin_signal: GPIO_AD_B0_02, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
  - {pin_num: H10, peripheral: LPSPI3, signal: SDO, pin_signal: GPIO_AD_B0_01, slew_rate: Slow, software_input_on: Disable, open_drain: Disable, speed: MHZ_100, drive_strength: R0_6,
    pull_keeper_select: Keeper, pull_keeper_enable: Enable, pull_up_down_config: Pull_Down_100K_Ohm, hysteresis_enable: Disable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : LPSPI3_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void LPSPI3_InitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);          /* iomuxc clock (iomuxc_clk_enable): 0x03u */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_00_LPSPI3_SCK,        /* GPIO_AD_B0_00 is configured as LPSPI3_SCK */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_01_LPSPI3_SDO,        /* GPIO_AD_B0_01 is configured as LPSPI3_SDO */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_02_LPSPI3_SDI,        /* GPIO_AD_B0_02 is configured as LPSPI3_SDI */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_03_LPSPI3_PCS0,       /* GPIO_AD_B0_03 is configured as LPSPI3_PCS0 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_00_LPSPI3_SCK,        /* GPIO_AD_B0_00 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_01_LPSPI3_SDO,        /* GPIO_AD_B0_01 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_02_LPSPI3_SDI,        /* GPIO_AD_B0_02 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
  IOMUXC_SetPinConfig(
      IOMUXC_GPIO_AD_B0_03_LPSPI3_PCS0,       /* GPIO_AD_B0_03 PAD functional properties : */
      0x10B0u);                               /* Slew Rate Field: Slow Slew Rate
                                                 Drive Strength Field: R0/6
                                                 Speed Field: medium(100MHz)
                                                 Open Drain Enable Field: Open Drain Disabled
                                                 Pull / Keep Enable Field: Pull/Keeper Enabled
                                                 Pull / Keep Select Field: Keeper
                                                 Pull Up / Down Config. Field: 100K Ohm Pull Down
                                                 Hyst. Enable Field: Hysteresis Disabled */
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
LPSPI3_DeinitPins:
- options: {coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: M14, peripheral: GPIO1, signal: 'gpio_io, 00', pin_signal: GPIO_AD_B0_00}
  - {pin_num: H10, peripheral: GPIO1, signal: 'gpio_io, 01', pin_signal: GPIO_AD_B0_01}
  - {pin_num: M11, peripheral: GPIO1, signal: 'gpio_io, 02', pin_signal: GPIO_AD_B0_02}
  - {pin_num: G11, peripheral: GPIO1, signal: 'gpio_io, 03', pin_signal: GPIO_AD_B0_03}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/*FUNCTION**********************************************************************
 *
 * Function Name : LPSPI3_DeinitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 *END**************************************************************************/
void LPSPI3_DeinitPins(void) {
  CLOCK_EnableClock(kCLOCK_Iomuxc);          /* iomuxc clock (iomuxc_clk_enable): 0x03u */

  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_00_GPIO1_IO00,        /* GPIO_AD_B0_00 is configured as GPIO1_IO00 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_01_GPIO1_IO01,        /* GPIO_AD_B0_01 is configured as GPIO1_IO01 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_02_GPIO1_IO02,        /* GPIO_AD_B0_02 is configured as GPIO1_IO02 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
  IOMUXC_SetPinMux(
      IOMUXC_GPIO_AD_B0_03_GPIO1_IO03,        /* GPIO_AD_B0_03 is configured as GPIO1_IO03 */
      0U);                                    /* Software Input On Field: Input Path is determined by functionality */
}

/*******************************************************************************
 * EOF
 ******************************************************************************/
