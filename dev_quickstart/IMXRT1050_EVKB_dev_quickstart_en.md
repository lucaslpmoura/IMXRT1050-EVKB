# **IMXRT1050-EVKB Evaluation Board**

<img src="fig/imxrt1050evkb.png" width= 30%>

## Basic Information [^1]

[^1]: click to show/hide (where supported)

> Main On-board Micro-Controller Unit (MCU) comes from <img src="fig/NXP_logo.png" width = 5%> i.MX-RT1050 family:<br>
>  **MIMXRT1052**
>
> <details>
> <summary><b>Pinout</b> and <b>schema</b> of the board</summary>
>  <img src="fig/imxrt1050evkb_pinout_front.png" width = 25%><figcaption>Front</figcaption><br>
>  <img src="fig/imxrt1050evkb_pinout_back.png" width = 25%><figcaption>Back</figcaption><br>
>   <a href="pdf/imxrt1050evkb_schematic.pdf">Schematic</a>
> </details>
>
> <details>
> <summary>Further <b>documentation</b></summary>
> <ul>
> <li><a href="https://www.nxp.com/design/design-center/development-boards-and-designs/MIMXRT1050-EVK">Main Page</a>
> from <img src="fig/NXP_logo.png" width = 5%>, with relevant "getting started" guides and hardware references.</li>
>
> <li>Based on the <a href="https://developer.arm.com/Processors/Cortex-M7">Cortex®-M7</a> from <img src="fig/ARM_logo.png" width=5%></li>
>   <ul>
>   <li><a href="https://developer.arm.com/documentation/ddi0489/">Arm® Cortex®-M7 Processor Technical Reference Manual</a>
>    - an overview of the processor, a good starting place.
>   </li>
>   <li>
>   <a href="https://developer.arm.com/documentation/dui0646">Arm® Cortex®-M7 Devices Generic User Guide</a>
>   - a more in-depth document, useful for programming the processor.
>   </li>
>   <li>
>   <a href="https://developer.arm.com/documentation/ddi0403/latest/">ARMv7-M Architecture Reference Manual</a>
>   - very detailed, approx. 1000-page documentation for CPU etc.
>   </li>
>   <ul>
> </ul>
> </details>
>
> <!--
> <details><summary>Recommended <b>reading</b></summary>
> </details>
> -->
> 
>
## Development (means and advice/tips)

### Basic development instruments

<details><summary>
<img src="fig/MCUXpresso_logo.png" width=1.85%> MCUXpresso IDE</summary>

> * can be installed (Win10+, MacOS13+, Ubuntu20+) as a standalone application or used as an extension of MCUXpresso for VS Code within VSC
> * [Home Page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE)
> * Typical post-installation steps:
>   1. **Run** MCUXpresso, enter the path to your workspace; I recommend closing the Welcome tab
>      > in the *Installed SDKs* section, you can (optionally, or later edit) add SDK packages obtained e.g. from [MCUXpresso SDK Builder](https://mcuxpresso.nxp.com/en) using Drag&Drop style
>   2. **Create** a new (C/C++) project, in the wizard, gradually select the MCU (MIMXRT1050 -> MIMXRT1052xxxB), the project type and its settings
>   3. **Finish implementing** the embedded application in the *src/* subdirectory of the project
>   4. **Build** your project
>      > * e.g. by clicking the "hammer" icon in the toolbar, pressing "Build" on the Quickstart panel or using the keyboard shortcut <CTRL+B>
>      > * after successful compilation, the resulting application (firmware) will appear in the *Binaries/* section of the project in binary format
>   5. Start the **Debug** process
>      > * e.g. by pressing the appropriate "probe" icon (typ. PEmicro) on the Quickstart panel, the "bug" icon on the toolbar or by pressing the right mouse button in the Project Explorer section, then selecting "Debug As", etc.

Tips:
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

> * Configure your application-specific SDK for the appropriate platform (board, microcontroller, etc.)
>   > Import the SDK into:
>   <ul>
>   <li><a href="https://community.nxp.com/t5/MCUXpresso-IDE-Knowledge-Base/Importing-an- MCUXpresso-SDK-into-MCUXpresso-IDE/ta-p/1101175">MCUXpresso</a></li>
>   </ul>
> 
> * [Home Page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-software-development-kit-sdk:MCUXpresso-SDK)

</details>


<details><summary>FreeMASTER</summary>

> * [Home Page](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-software-development-kit-sdk:MCUXpresso-SDK)

</details>

### General Advice/Tips

<details> <summary>Development</summary>
<ul>
<li>

> Building a new project (MCUXpresso) <br>
> > Before you build your project, make sure it is selected at the Projecte Workspace (the tab on the left side of the screen, that looks like an file manager.) 
Otherwise, you might build a different project and get unexpected results. It is also good practice to always clean the project before you do any builds, by clicking on the "broom" icon.
</li>
<li>

> Recommendations before starting a new debugging process (MCUXpresso) <br>
 > > Before starting a new Debug process, make sure that the previous debug is terminated - if you are not sure about terminating,
(the red squares for Terminate should "disappear" from the toolbars); otherwise, it may happen that pegdbserver, running as a background process, will not terminate properly and it will have to be removed before starting a new Debug process (e.g. using the Task Manager in Windows).
</li>
</ul>
</details>

<!-- 
<details>
<summary>Further (manuals, etc.)</summary>
</details>
-->

### Examples
<details>
<summary> Minimalistic Code </summary>
</details>

<details>
<summary> LED Blink using interrupt </summary>
</details>

<details>
<summary> Interrupt triggered by pressing a button. </summary>
</details>

<details>
<summary> LED control using UART for user interface. </summary>
</details>

<br>
You are also encouraged to look into the examples provided by the SDK.


