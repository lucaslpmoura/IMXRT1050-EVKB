Overview
========
The spdif_interrupt_transfer example shows how to use spdif driver with interrupt:

In this example, one spdif instance playbacks the audio data recorded by the same spdif instance using interrupt.

Notice: Please use 48KHz sample rate for PC playback and set SPDIF output device to 48KHz.

Toolchain supported
===================
- IAR embedded Workbench 8.11.2
- Keil MDK 5.23
- GCC ARM Embedded 2016-5.4-q3
- MCUXpresso10.1.0

Hardware requirements
=====================
- Mini/micro USB cable
- EVK-MIMXRT1050 board
- Personal Computer
- Two SPDIF RCA lines
- Soundcacrd support SPDIF interface

Board settings
==============
Make sure J13 and J15 are on.

Prepare the Demo
================
1.  Connect a USB cable between the host PC and the OpenSDA USB port on the target board.
2.  Connect J14 with SPDIF soundcard output inteface, connect J18 with SPDIF soundcard input interface.
3.  Playback music using the SPDIF soundcard, make the SPDIF signals input to MIMXRT1050 board.
4.  Open a serial terminal with the following settings:
    - 115200 baud rate
    - 8 data bits
    - No parity
    - One stop bit
    - No flow control
5.  Download the program to the target board.
6.  Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
After run the demo, you can hear the music playbacked from SPDIF soundcacrd, the log below shows the output of the example in the terminal window:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SPDIF example started!
SPDIF example finished!
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Customization options
=====================

