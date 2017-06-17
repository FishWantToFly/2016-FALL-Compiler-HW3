* Run DemoBlink with eflash on Andino/M1 (command line).

(1) Please install Arduino IDE with version v1.6.4 / v1.6.5 first (Version after v1.6.5 is not supported yet).
      You can reference Andino M1_UM131_V1.1.docx to setup the environment.
    [Windows's toolchain]
        %APPDATA%\Arduino15\packages\Andino\tools\nds32le-elf-mculib-v3m\4.0.3\bin
    [Burner]
        %APPDATA%\Arduino15\packages\Andino\tools\m2c_burner\0.0.1\m2c_newton.exe
    [batch file to launch Cygwin]
        %APPDATA%\Arduino15\packages\Andino\tools\nds32le-elf-mculib-v3m\4.0.3\cygwin\Cygwin.bat

(2) Launch Cygwin console
    Double click "Cygwin.bat" in Cygwin folder to Launch Cygwin.
    Press Enter key if needed.

(3) Decompress tarball to your local folder by Cygwin command line console.
    $ cd <your-folder-that-tarball-is-located>
    $ tar xvfz DemoBlink.tar.gz

(4) setup enviornment and build DemoBlink demo
    $ export PATH="/cygdrive/c/Documents and Settings/<user-name>/Application Data/Arduino15/packages/Andino/tools/nds32le-elf-mculib-v3m/4.0.3/bin":$PATH
    $ cd <your-folder-that-tarball-is-decompressed>
    $ make clean
    $ make

(5) Please connect Andino/M1 board to PC and then Launch ICEman (on Cygwin console)
      Double click "Cygwin.bat" in Cygwin folder to Launch Cygwin.
    $ cd "/cygdrive/c/Documents and Settings/<user-name>/Application Data/Arduino15/packages/Andino/tools/m2c_burner/0.0.1"
    $ ./ICEman.exe -p 1234

    <message>
    Andes ICEman v3.2.2 (OpenOCD) BUILD_ID: 2015082815
    Burner listens on 2354 <=========== < Please check the burner port setting >
    Telnet port: 4444
    TCL port: 6666
    Open On-Chip Debugger 0.8.0-dev-g1a84463 (2015-08-28-15:34)
    Licensed under GNU GPL v2
    For bug reports, read
            http://openocd.sourceforge.net/doc/doxygen/bugs.html
    Andes AICE-MINI v1.0.2
    There is 1 core in target
    Core #0: EDM version 0x1010
    JTAG frequency 12 MHz
    The core #0 listens on 1234.  <=========== < Please check the core0#0 port setting >
    ICEman is ready to use.

(6) Open your terminal and give the setting as below:
    Port        : please reference Deive Manager to choose your com port.
    Baud rate   : 38400
    Data        : 8 bit
    Parity      : none
    STOP        : 1 bit
    Flow control: none

(7) Burn "arduino-Blink.bin" with m2c_newton.exe (on Cygwin console)
    $ cd "/cygdrive/c/Documents and Settings/<user-name>/Application Data/Arduino15/packages/Andino/tools/m2c_burner/0.0.1"
    $ ./m2c_newton.exe --image="<your-folder-that-tarball-is-decompressed>/arduino-Blink.bin"

    <Burning Message>
    M2C Burner BUILD_ID: 20150623
    RESET_HOLD CPU
    Image size:13664
    Flash base address: 0x0
    Start Init Flash Controller
    Flash Init
    erase from address = 0
    total erasing block 7, size:0x3800
    erasing block 1 (0x0 ~ 0x800)
    erasing block 2 (0x800 ~ 0x1000)
    erasing block 3 (0x1000 ~ 0x1800)
    erasing block 4 (0x1800 ~ 0x2000)
    erasing block 5 (0x2000 ~ 0x2800)
    erasing block 6 (0x2800 ~ 0x3000)
    erasing block 7 (0x3000 ~ 0x3800)
    burn flash from 0x0 to 0x3560
    burning
    Netwon Burn: base:0x0, size:0x3560.

    0%
    20%
    50%
    80%
    Flash burning done.

[NOTE-1] How to get objdump result
(1) Launch Cygwin console
    Double click "Cygwin.bat" in Cygwin folder to Launch Cygwin.
      - %APPDATA%\Arduino15\packages\Andino\tools\nds32le-elf-mculib-v3m\4.0.3\cygwin\Cygwin.bat
    Press Enter key if needed.

(2) Decompress tarball to your local folder by Cygwin command line console.
    $ cd <your-folder-that-tarball-is-decompressed>
    $ tar xvfz DemoBlink.tar.gz

(3) setup enviornment and build DemoBlink demo
    $ export PATH="/cygdrive/c/Documents and Settings/<user-name>/Application Data/Arduino15/packages/Andino/tools/nds32le-elf-mculib-v3m/4.0.3/bin":$PATH
    $ cd <your-folder-that-tarball-is-decompressed>
    $ make clean
    $ make

(4) get the result from objdump
     You can get arduino-Blink.s which is at Demo_Blink, or type commnad as follow:
    $ nds32le-elf-objdump.exe -d -S arduino-Blink.elf  > objdump.txt

[NOTE-2] How to debug with gdb (please follow the steps below on Cygwin console).

------- Please make sure you have burned your arduino-Blink.bin first before debugging ------

Launch one Cygwin console
    $ cd "/cygdrive/c/Documents and Settings/<user-name>/Application Data/Arduino15/packages/Andino/tools/m2c_burner/0.0.1"
    $ ./ICEman.exe -p 1234

Launch another Cygwin console
    $ cd "/cygdrive/c/Documents and Settings/<user-name>/Application Data/Arduino15/packages/Andino/tools/m2c_burner/0.0.1"
    $ ./m2c_newton.exe --image="<your-folder-that-tarball-is-decompressed>/arduino-Blink.bin"
    $ export PATH="/cygdrive/c/Documents and Settings/<user-name>/Application Data/Arduino15/packages/Andino/tools/nds32le-elf-mculib-v3m/4.0.3/bin":$PATH
    $ nds32le-elf-gdb.exe <your-folder-that-tarball-is-decompressed>/arduino-Blink.elf
    $ target remote : 1234
    $ reset-and-hold
    $ hb *main
    $ c
    $ display/5i $pc
    $ si








