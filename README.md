# wb55-ble

Simple blinky for the STM32WB55 Nucleo board

## Build instructions

### macOS

#### Setting up development tools

1. Download and install [CLion](https://www.jetbrains.com/clion/download/#section=mac)
2. Install the latest version of OpenOCD by executing the following command:

    ```bash
    brew install --HEAD openocd
    ```

3. Download the latest [ARM toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) and extract it to `~/bin/`.
4. Add the toolchain to the path by adding the full path to the `bin/` subdirectory to the `/etc/paths` file.
5. Download and install the [Java JDK](https://www.oracle.com/java/technologies/javase-jdk14-downloads.html)
6. Download [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html).  Extract it and install it by executing the following command and going though the installation steps:

    ```bash
    sudo java -jar SetupSTM32CubeMX-5.6.1.exe
    ```

#### Upgrading programmer firmware

1. Download the [STLINK firmware upgrader](https://my.st.com/content/my_st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-programmers/stsw-link007.license=1588261082888.product=STSW-LINK007.version=2.36.26.html).
2. Extract the zip file.
3. Open a terminal in the extracted directory and execute the following command:

    ```bash
    java -jar AllPlatforms/STLinkUpgrade.jar
    ```

4. Go through the upgrade process in the application

#### Configure CLion project

1. Clone this git repository
2. Open this project in CLion
3. Open the **Preferences** window
4. Under **Build, Execution, Deployment -> Embedded Development**, add the OpenOCD location: `/usr/local/bin/openocd`.
5. Click **OK**
6. Click **File -> Reload CMake Project**
7. It should be able to process the CMake file correctly.  If there are issues finding the ARM gcc compilers, double-check that the path was added correctly to the `/etc/paths` file.
8. Test that the program compiles by building the `wb55-blef` configuration.
9. Click **Edit Configurations...**
10. Set **Target** and **Executable** to `wb55-blef` and set **Board config file** to `board/st_nucleo_wb55.cfg`.
11. Click **OK**.
12. Connect your Nucleo board via USB.
13. Run the `OCD wb55-bleuild configuration.  The program should get flashed to the board and the green LED should start blinking every second.
