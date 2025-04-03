Overview
========
The flexio_lpi2c_interrupt example shows how to use flexio i2c master  driver in interrupt way:

In this example, a flexio simulated i2c master connect to a LPI2C slave

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

Known Issue:
- sdram target of ARM GCC can’t finish successfully.

Board settings
==============
To make this example work, connections needed to be as follows:

    FLEXIO_I2C        connected to  LPI2C1
SCL     SW5-2           -->        J23-6
SDA     SW5-1           -->        J23-5

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the OpenSDA USB port on the target board.
2.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
3.  Download the program to the target board.
4.  Launch the debugger in your IDE to begin running the demo.

Running the demo
================
You can see the similar message shows following in the terminal if the example runs successfully.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FlexIO I2C interrupt - LPI2C interrupt
Master will send data :
0x00  0x01  0x02  0x03  0x04  0x05  0x06  0x07
0x08  0x09  0x0A  0x0B  0x0C

Slave received data :
0x00  0x01  0x02  0x03  0x04  0x05  0x06  0x07
0x08  0x09  0x0A  0x0B  0x0C
~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

