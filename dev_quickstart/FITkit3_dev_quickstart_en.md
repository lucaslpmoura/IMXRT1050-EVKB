# **FITkit3 (Minerva)**

<img src="fig/brd_FITkit3.png" width = 25%>

## Basic information[^1]

[^1]: click to show/hide (where supported)

> Main on-board Micro-Controller Unit (microcontroller, MCU) comes from <img src="fig/NXP_logo.png" width = 5%>, **Kinetis** K60 family:<br>
**MK60DN512VMD100**


<details><summary><b>Pinout</b> and <b>schema</b> of the board</summary>

> <img src="fig/brd_FITkit3_pinout.png" width = 25%><br>
> **Board schema:** [complete](pdf/brd_FITkit3_schema.pdf), 
[cutout](pdf/brd_FITkit3_schema_cutout_p6.pdf)<br>
<img src="fig/brd_FITkit3_schema_cutout_p6.png" width = 25%>

</details>

<details><summary>Further <b>documentation</b></summary>

> * based on [Cortex®-M4](https://developer.arm.com/Processors/Cortex-M4) od [<img src="fig/ARM_logo.png" width=5%>](https://www.arm.com/)
>   * [Arm® Cortex®-M4 Processor Technical Reference Manual](https://developer.arm.com/documentation/100166/latest/)<br> 
>     basic overview, relatively cursory, approx. 100-page documentation (information is not enough for programming)
>   * [Cortex™-M4 Devices Generic User Guide](https://developer.arm.com/documentation/dui0553/latest/)
>     more detailed, approx. 300-page documentation usable for basic programming
>   * [ARMv7-M Architecture Reference Manual](https://developer.arm.com/documentation/ddi0403/latest/)
>     very detailed, approx. 1000-page documentation for CPU etc.
> * [K60 Sub-Family Reference Manual](pdf/brd_FITkit3_refman.pdf)<br>
>   most of the necessary information can be found in this documentation - it contains all the information for programming the functionality from NXP

</details>

<details><summary>Recommended <b>reading</b></summary>


> **Clock (sub-)system**[^2]
> * clock distribution ([p. 183](pdf/brd_FITkit3_refman.pdf#page=183)) and their diagram ([p. 184](pdf/brd_FITkit3_refman.pdf#page=184))
> * **SIM_SOPT1** register ([p. 287](pdf/brd_FITkit3_refman.pdf#page=287))
> * **SIM_SOPT5** register ([p. 295](pdf/brd_FITkit3_refman.pdf#page=295))
> * **SIM_SCGCx** registers (from [p. 300](pdf/brd_FITkit3_refman.pdf#page=300))
> * **SIM_CLKDIVx**, **OUTDIVx** registers (from [p. 311](pdf/brd_FITkit3_refman.pdf#page=311))
> * **MCG_C1** register ([p. 570](pdf/brd_FITkit3_refman.pdf#page=570))
> * **MCG_C4** register ([p. 573](pdf/brd_FITkit3_refman.pdf#page=573))


> **Inputs/Outputs of MCU**[^2]
> * MCU **pinout** (from [p. 243](pdf/brd_FITkit3_refman.pdf#page=243)) 
> * **PORTx_PCRy** - register used to configure a pin *y* of a port *x*  (from [p. 271](pdf/brd_FITkit3_refman.pdf#page=271)) 
> * **GPIO** - General-Purpose Inputs/Outputs (from [p. 1741](pdf/brd_FITkit3_refman.pdf#page=1741)) 

> **Exception/Interrupt (sub-)System and its controller (NVIC)**[^2]
> * IRQ masks, from IRQ source[^4] via NVIC level[^6] to CPU level[^7]
> * ISF (Interrupt Status Flag) clearing[^5]
> * for more, consult, e.g., [Exceptions](https://developer.arm.com/documentation/ddi0337/e/Exceptions?lang=en) či [A Practical guide to ARM Cortex-M Exception Handling](https://interrupt.memfault.com/blog/arm-cortex-m-exceptions-and-nvic)

</details>


[^2]: References to the information below are, with rare exceptions, to the document [K60 Sub-Family Reference Manual](pdf/brd_FITkit3_refman.pdf)
[^4]: e.g. for a port pin by setting the value of the IRQC field in the PORT_PCR register to a non-zero value (from [p. 278](pdf/brd_FITkit3_refman.pdf#page=278))
[^5]: e.g. for a port pin by writing the value 1 to ISF (i.e. bit at index 24) in the PORT_PCR register (from [p. 277](pdf/brd_FITkit3_refman.pdf#page=277)) or by writing the value 1 to the corresponding bit in the PORTx_ISFR register (from [p. 277](pdf/brd_FITkit3_refman.pdf#page=277))
[^6]: see, e.g., NVIC_ISERx, NVIC_ICPRx registers in [Cortex™-M4 Devices Generic User Guide](https://developer.arm.com/documentation/dui0553/latest/)
[^7]: see, e.g., IPSR, PRIMASK, FAULTPRI, BASEPRI registers in [Cortex™-M4 Devices Generic User Guide, cca from p. 19](https://developer.arm.com/documentation/dui0553/latest/) či [ARMv7-M Architecture Reference Manual, cca from p. 575](https://developer.arm.com/documentation/ddi0403/latest/)

## Development (means and advice/tips)

### Basic development instruments

<details><summary>
<img src="fig/KDS_logo.png" width=2.25%> Kinetis Design Studio (KDS) IDE</summary>

> * can be used (on Win 7-10, Linux Ubuntu 10/RedHat 7/CentOS 7, Mac 10.x), but support for the tool is ending; unless there is a specific reason to use it, I recommend using MCUXpresso instead
> * [home page](https://www.nxp.com/design/designs/design-studio-integrated-development-environment-ide:KDS_IDE?tab=Design_Tools_Tab)
> * Typical post-installation steps:
>   1. **Start** KDS, enter the path to your workspace; I recommend closing the Welcome tab
>      > if interested, it is possible (optionally, or later modified) to add SDK packages, however, it requires some effort - see e.g. [Using Kinetis Design Studio v3.x with Kinetis SDK v2.0](https://community.nxp.com/t5/Kinetis-Design-Studio-Knowledge/Using-Kinetis-Design-Studio-v3-x-with-Kinetis-SDK-v2.0/ta-p/1107131)
>   2. **Create** a new (C/C++) project, in the wizard, gradually select the MCU (Kinetis K60 -> K60DN512xxx10), the project type and its settings
>      > You will probably choose the following project types:
		"Kinetis SDK 1.x ..." (project without SDK or with an older version of SDK - the choice can be made in u4init in the Rapid Application Development section)
		or 
		"Kinetis SDK 2.x" (Project with SDK version 2)
>   3. **Finish implementing** the embedded application in the *src/* subdirectory of the project
>   4. **Build** your project
>      > * e.g. by clicking the "hammer" icon in the toolbar, pressing "Build" on the Quickstart panel or using the keyboard shortcut <CTRL+B>
>      > * after successful compilation, the resulting application (firmware) will appear in the *Binaries/* section of the project in binary form
>   5. Start the **Debug** process, e.g.:
>      > * by expanding the "bug" icon on the toolbar -> Debug Configurations -> double-click with the left mouse button on GDB PEMicro Interface Debugging -> select ..._Debug_PNE -> press Debug
>      > * by right-clicking in the Project Explorer section, then selecting "Debug As" -> Debug Configurations -> ...

Tips:
> * to redirect standard input/output to the KDS environment, you can use, for example, the so-called **Semihosting** (similarly, Telnet or GDB client) - see:
>   > * Debug Configurations -> Startup -> Enable Semihosting, for more see e.g. [Semihosting with Kinetis Design Studio](https://mcuoneclipse.com/2014/06/06/semihosting-with-kinetis-design-studio/)
> * to use floating point support in printf() etc., KDS must be set accordingly
>   > see, e.g., [Adding floating point support for printf() and scanf() to your project](https://community.nxp.com/t5/Kinetis-Design-Studio/Adding-floating-point-support-for-printf-and- scanf-to-your/m-p/620949#M7938)



</details>

<details><summary>
<img src="fig/MCUXpresso_logo.png" width=1.85%> MCUXpresso IDE</summary>

> * user-friendly and otherwise improved KDS follower
> * can be installed (Win10+, MacOS13+, Ubuntu20+) as a standalone application or used as an extension of MCUXpresso for VS Code within VSC
> * [home page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE)
> * Typical post-installation steps:
>   1. **Run** MCUXpresso, enter the path to your workspace; I recommend closing the Welcome tab
>      > in the *Installed SDKs* section, you can (optionally, or later edit) add SDK packages obtained e.g. from [MCUXpresso SDK Builder](https://mcuxpresso.nxp.com/en) using Drag&Drop style
>   2. **Create** a new (C/C++) project, in the wizard, gradually select the MCU (Kinetis K60 -> K60DN512xxx10), the project type and its settings
>   3. **Finish implementing** the embedded application in the *src/* subdirectory of the project
>   4. **Build** your project
>      > * e.g. by clicking the "hammer" icon in the toolbar, pressing "Build" on the Quickstart panel or using the keyboard shortcut <CTRL+B>
>      > * after successful compilation, the resulting application (firmware) will appear in the *Binaries/* section of the project in binary format
>   5. Start the **Debug** process
>      > * e.g. by pressing the appropriate "probe" icon (typ. PEmicro) on the Quickstart panel, the "bug" icon on the toolbar or by pressing the right mouse button in the Project Explorer section, then selecting "Debug As", etc.

TipS:
> * to redirect standard input/output to the MCUXpresso environment, you can use, for example, the so-called **Semihosting** (similarly, Telnet or GDB client) - see:
>   > * Quickstart panel -> Miscelaneous -> Quick Settings -> SDK Debug Console -> Semihost console
>   > * Debug Configurations -> Startup -> Enable Semihosting

</details>


<details><summary>
<img src="fig/VSC_logo.png" width=1.5%> Visual Studio Code (VSC)
</summary>

> 1. [Download](https://code.visualstudio.com/Download) and **install** VSC
> 2. Install in **extensions**
>    * [MCUXpresso for VS Code](https://www.nxp.com/design/design-center/software/embedded-software/mcuxpresso-for-visual-studio-code:MCUXPRESSO-VSC)
> 3. Create **new project** (or import an existing project or repository)
>    > select project type (MCUXpresso SDK or Zephyr)
> 4. **Finish implementing** the embedded application in the project (typically in C/C++)
> 5. **Build** the project
>    > the result should be a binary file (firmware) executable on the target platform
> 6. **Install** any missing **Debug Probes** (SEGGER, LinkServer, but especially **PEmicro**)
> 7. **Select** a Debug Probe supported by the board (typ. PEmicro) and **start** Debug

</details>


<details><summary>Software Development Kit (SDK) Builder</summary>

> * configure your application-specific SDK for the appropriate platform (board, microcontroller, etc.)
>   > import the SDK into [KDS](Using Kinetis Design Studio v3.x with Kinetis SDK v2.0), [MCUXpresso](https://community.nxp.com/t5/MCUXpresso-IDE-Knowledge-Base/Importing-an- MCUXpresso-SDK-into-MCUXpresso-IDE/ta-p/1101175), ...
> * [home page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-software-development-kit-sdk:MCUXpresso-SDK)

</details>


<details><summary>FreeMASTER</summary>

> * [home page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-software-development-kit-sdk:MCUXpresso-SDK)

</details>


<details><summary><img src="fig/PEmicro_logo.png" width=2.0%> PEmicro drivers etc.</summary>

> * [PEmicro NXP_Kinetis Device Support](https://www.pemicro.com/arm/device_support/NXP_Kinetis/index.cfm)

</details>


<details><summary><img src="fig/Segger_logo.png" width=2.5%> Segger support (J-Link/Trace, System View aj.)</summary>

> * [Supported Devices - NXP - Kinetis K6x](https://www.pemicro.com/arm/device_support/NXP_Kinetis/index.cfm)
> * [downloads](https://www.segger.com/downloads/)

</details>





### General Advice/Tips

<details>
<summary>Development</summary>

> * How to re-run an application (KDS) loaded in the MCU
>   > If you have not changed the source files, there is no need to terminate the current debugging (Terminate, <CTRL+F2>), recompile the application, compile it and start the debugger again, including the need to load the application into the MCU memory and then run the application again (Resume, <F8>).<br>
>   > It is enough to restart the application (even if it is running) (e.g. by pressing the Restart button on the toolbar) and then start it again (Resume, <F8>)
> * Recommendations before starting a new debugging process (KDS)
>   > Before starting a new Debug process, make sure that the previous debug is terminated - if you are not sure about terminating, do Terminate, <CTRL+F2>
(the red squares for Terminate should "disappear" from the toolbars); otherwise, it may happen that pegdbserver, running as a background process, will not terminate properly and it will have to be removed before starting a new Debug process (e.g. using the Task Manager in Windows).

</details>

<details><summary>Further (manuals etc.)</summary>

 
</details>


<style>
pre[class*=language-]
{font-size: 0.8em;} 
</style>

### Examples

Although the implicitly generated main.c source code of the newly created project
is slightly different in KDS and MCUXpresso, the programming of the embedded application is practically the same
> for a typical project structure, see e.g. [CMSIS-Core Device Templates](https://arm-software.github.io/CMSIS_5/Core/html/templates_pg.html),
see a few common examples below

<details><summary>Minimalistic code</summary>

> <details><summary>KDS</summary>
> 
> ```C++
> #include "MK60D10.h"
> static int i = 0;
> 
> int main(void) {
>     /* Write your code here */
> 
>     /* This for loop should be replaced. By default this loop allows a single stepping. */
>     for (;;) {
>         i++;
>     }
>     /* Never leave main */
>     return 0;
> }
> ```
> 
> </details>
>
> <details><summary>MCUXpresso</summary>
> 
> ```C++
> #include <stdio.h>
> #include "board.h"
> #include "peripherals.h"
> #include "pin_mux.h"
> #include "clock_config.h"
> #include "MK60D10.h"
> 
> int main(void) {
> 
>     /* Init board hardware. */
>     BOARD_InitBootPins();
>     BOARD_InitBootClocks();
>     BOARD_InitBootPeripherals();
> 
>     volatile static int i = 0; /* Force the counter to be placed into memory. */
>     while(1) { /* Enter an infinite loop, just incrementing a counter. */
>         i++ ;
>         __asm volatile ("nop"); /* 'Dummy' NOP to allow single stepping of while() */
>     }
>     return 0 ;
> }
> ```
> 
> </details>

</details>

<details><summary>Clock (sub-)system settings</summary>

> Enabling and correctly setting the clock source for each used part of the system (chip pins/ports, communication interfaces, timers, etc.) is absolutely essential to ensure the required functionality.
>
> * for more information, see e.g. [K60 Sub-Family Reference Manual](pdf/brd_FITkit3_refman.pdf), sections 25.3 Memory Map/Register Definition, 25.4.1 MCG mode, etc.
> * a number of support tools can help to better understand the clock subsystem, or make its settings easier - see e.g. MCUXpresso menu ConfigTools -> Clocks

Example of settings:

```C++
	/* set DCO out (MCGOUTCLK) frequency to 48 MHz */
    MCG_C4 |= ( MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x01) );
		
	/* set clock divisors to 1 to let all frequencies at their max value */
    SIM_CLKDIV1 |= SIM_CLKDIV1_OUTDIV1(0x00);

	/* Enable clock for UART5 needed, e.g., to communicate via a terminal */
	SIM_SCGC1 |= SIM_SCGC1_UART5_MASK;

	/* Enable clock for ports A-E */
	SIM_SCGC5 |= (SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK
			  | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK 
			  | SIM_SCGC5_PORTE_MASK );

    WDOG_STCTRLH &= ~WDOG_STCTRLH_WDOGEN_MASK; /* disable WDG */
```

Příklad nastavení (FEI -> BPLE)[^10]:

```C++
//  Configures MCG to run in BLPE mode from FEI mode -> 50 MHz
void MCG_FEI_BLPE() {
	// Select External Reference Clock in MCG (Transition to FBE from FEI)
	// C1[CLKS] written to 10
	MCG->C1 = MCG_C1_CLKS(2);

	// Wait for Reference clock to switch to external reference
	while (MCG->S & MCG_S_IREFST_MASK);

	// Wait for MCGOUT to switch over to the external reference clock
	while (((MCG->S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x2);

	// Transition to bypassed low power external mode (BLPE)
	// C2[LP] written to 1
	MCG->C2 = MCG_C2_LP_MASK;
}
```

[^10]: after reset, the MCU is in FLL Engaged Internal (FEI) mode, see for more details e.g.
section 25.4.1 MCG mode state diagram in [K60 Sub-Family Reference Manual](pdf/brd_FITkit3_refman.pdf)
or [Power Management for Kinetis MCUs (AN4503)](https://www.nxp.com/docs/en/application-note/AN4503.pdf)

Example of settings (BPLE -> FEI):

```C++
/* Configures MCG to run in FEI mode from BLPE mode. 
   For K60 0M33Z masks -> 25 MHz; else 20.97 MHz 
*/
void MCG_BLPE_FEI() {
	// Transition to FBE
	MCG->C2 = 0;

	// Transition to FEI
	MCG->C1 = MCG_C1_IREFS_MASK;

	// Wait for Reference clock to switch to internal reference
	while ((MCG->S & MCG_S_IREFST_MASK) == 0);

	// Wait for MCGOUT to switch over to the FLL clock
	while (((MCG->S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) != 0x0);
}
```

</details>

<details><summary>UART settings (e.g. for logging or interacting with the user via terminal)</summary>
<br>

> FITkit3 has six UART interfaces (UART0 - UART5) -
of which **UART5** is intended for terminal communication.

```C++
int sysclk = 50000,	/* core/system clock [in MHz] */ 
int baud = 115200;	/* Baud rate [bit/s] */
//
uint16_t sbr, brfa; /* auxiliary variables */
uint8_t temp;

SIM->SCGC1 |= SIM_SCGC1_UART5_MASK; /* enable the clock for UART5 */

/* DISable transmitter&receiver before changing the UART5 settings */
UART5->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);     	
UART5->C1 = 0;	/* configure the UART5 for 8-bit mode, no parity */

sbr = (uint16_t)((sysclk*1000)/(baud * 16)); /* calculate SBR */
temp = UART5->BDH & ~(UART_BDH_SBR(0x1F));   /* save BDH except of SBR */
/* set BD of UART5 */
UART5->BDH = temp | UART_BDH_SBR(((sbr & 0x1F00) >> 8));
UART5->BDL = (uint8_t)(sbr & UART_BDL_SBR_MASK);

/* check if a divider is needed to approach the desired baud rate */
brfa = (((sysclk*32000)/(baud * 16)) - (sbr * 32));
temp = UART5->C4 & ~(UART_C4_BRFA(0x1F)); /* save UARTx_C4 except of BRFA */
UART5->C4 = temp | UART_C4_BRFA(brfa);

/* ENable transmitter&receiver before changing the UART5 settings */
UART5->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
```

</details>


<details><summary>LED control using GPIO (General-Purpose Inputs/Outputs)</summary>

> * **four LEDs** are available on the board (D9 - D12)
>   > * working with them will be indicated, for their **connection I recommend studying** the board diagram
>   > * for simplicity, the **example will be limited** to only a subset of these LEDs
> * example leads to **periodic flashing of LEDs D9 and D12**
>   > * example leads to **periodic flashing of LEDs D9 and D12**

```C++
/* LED-related pins (see the board schema):
   D9:	port B, bit 5 
   D10:	port B, bit 4 
   D11:	port B, bit 3 
   D12:	port B, bit 2 
*/
#define LED_D9  0x20 // 1u << 5
#define LED_D10 0x10 // 1u << 4
#define LED_D11 0x8  // 1u << 3
#define LED_D12 0x4  // 1u << 2
#define LED_ALL (LED_D9 | LED_D10 | LED_D11 | LED_D12)

SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /* ENable clock for port B */

/* set PTB5 - PTB2 into the GPIO mode */
PORTB_PCR5 = PORTB_PCR4 = PORTB_PCR3 = PORTB_PCR2 = PORT_PCR_MUX(1);

GPIOB_PDDR = GPIO_PDDR_PDD(LED_ALL); /* set all LED pins to output mode */ 
GPIOB_PTOR = LED_ALL; /* turn all LEDs off as the cathode of a LED is controlled */

while(1) {
	GPIOB_PTOR ^= (D9 | D12);	/* toggle the state (ON <-> OFF) of D9, D12 */
	delay(1000);				/* time to hold the state */
}
```

> Note: the delay() function needs to be implemented, e.g. like this:

```C++
void delay(long long bound) {	/* active waiting (consumes the CPU time) */
  long long i;
  for(i=0;i<bound;i++) { };		/* you can place __NOP(); into the loop body */
}
```

</details>




<details><summary>Exception/Interrupt triggered by pressing a button</summary>

> * **five buttons** are available on the board (SW2 - SW6)
>   > * working with them will be indicated, for their **connection I recommend studying** the board diagram
>   > * For simplicity, the **example will be limited** to just one button (SW6), the implementation does not include solutions for flickering, etc.
> * example leads to **starting the interrupt handler** after every **press of SW6**
>   > * the interrupt handler contains only the action necessary to reset the ISF - the user response to the press (e.g. changing the LED state, generating a sound, output to the terminal) must be programmed into the interrupt handler
>   > * The example can be used as a basis for your own experimentation, e.g. with other buttons

```C++
/* Button-related pins (see the board schema):
   SW2:	port E, bit 10 
   SW3:	port E, bit 12 
   SW4:	port E, bit 27 
   SW5:	port E, bit 26 
   SW6:	port E, bit 11 
*/
#define BTN_SW2 0x400	  // 1u << 10
#define BTN_SW3 0x1000	  // 1u << 12
#define BTN_SW4 0x8000000 // 1u << 27
#define BTN_SW5 0x4000000 // 1u << 26
#define BTN_SW6 0x800	  // 1u << 11

SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK; /* ENable clock for port E */

/* ENable IRQs from SW6 via PORTE_PCR11 (PORTE->PCR[11]) */
PORTE_PCR11 = PORT_PCR_ISF_MASK		/* clear ISF (Interrupt Status Flag) */		
			| PORT_PCR_MUX( 1 )		/* set the GPIO mode */ 
			| PORT_PCR_IRQC( 0xA )	/* IRQ when a falling edge occurs */ 
			| PORT_PCR_PE_MASK		/* enable inner pull resistor */ 
			| PORT_PCR_PS_MASK;		/* set pull to the up (pull-up) mode */

NVIC_EnableIRQ( PORTE_IRQn ); /* ENable IRQ (91) from Port E at NVIC level */

/* handler of an IRQ comming from Port E, i.e., a button */
void PORTE_IRQHandler() { 
	...
	/* check if the IRQ originates from SW6 */
	if ( !(PTE->PDIR & BTN_SW6) ) {	/* YES */
		...
		/* clear ISF of Port E, pin 11 */
		PORTE_PCR11 |= PORT_PCR_ISF_MASK;
		/* ... the same using ISFR */
		PORTE_ISFR |= BTN_SW6;			  
	} else {						/* NO */
	    ...
	}
	...
	/* a different way of clearing ISF: affects each pin of Port E */
	PORTE_ISFR = PORT_ISFR_ISF_MASK;
}
```
</details>

