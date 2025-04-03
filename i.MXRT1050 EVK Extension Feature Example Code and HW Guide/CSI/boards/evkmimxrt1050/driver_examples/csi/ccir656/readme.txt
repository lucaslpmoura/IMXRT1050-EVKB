Overview
========
The CSI CCIR656 project shows how to receive the camera data using CSI driver,
the camera interface is CCIR656. In this example, you will see the camera input
image shown in the LCD. Please note that the camera input image resolution
might be smaller than the LCD panel, so part of the LCD panel might be blank.

Toolchain supported
===================
- IAR embedded Workbench 8.11.2
- Keil MDK 5.23
- GCC ARM Embedded 2016-5.4-q3

Hardware requirements
=====================
- Mini/micro USB cable
- EVK-MIMXRT1050 board
- Personal Computer
- RK043FN02H-CT LCD board
- OV7725 module

Board settings
==============
1. Connect the RK043FN02H-CT board.
2. Connect the OV7725 camera module.

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the OpenSDA USB port on the target board. 
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
4.  Download the program to the target board.
5.  Launch the debugger in your IDE to begin running the demo.

Running the demo
================
When the demo runs successfully, the camera received pictures are shown in the LCD.
Customization options
=====================

