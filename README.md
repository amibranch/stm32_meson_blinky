# Description

This project demonstrates, how the stm32-platform could be used with a toolchain, based entirely
on gcc and used with the meson build-system.
It simply just contains a small blinky-example.

# Requirements

Please ensure that the following tools are available on your system
* Arm-none-eabi build tools (gcc, gdb, binutils)
* Meson-build
* Stlink
* Openocd (for debugging)

# How To

## Compile

Choose a cross-compilation file or build your own, depending on the available development-board.

Simply execute:
```
$ meson setup --cross-file=stm32f407xx.cross build_f4
$ meson compile -C build_f4
```

## Flash

Either use the specific build-target:
`$ meson compile -C build_f4 flash`
Or simple use stlink by yourself:
`$ st-flash --reset write ./build_f4/sr/main.bin 0x8000000`

## Detecting your device

If stlink has problems, ensure that the connection is up and the device is detected by the stlink
software. You can do this by the following command:
`st-info --probe`

## Debugging

You can debug your code, with openocd:
```
$ openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg

# On a different terminal:
$ arm-none-eabi-gdb
(gdb) file build_f4/src/main.elf
(gdb) target remote localhost:3333
(gdb) n
```

Or simply follow the instructions from here:
<https://stackoverflow.com/q/38033130/4918084>

Please note:
For the WeAct v3.0, I had to change the `reset_config` to `none`, as suggeset here:
<https://stackoverflow.com/a/49195787/4918084>

Alternative, using st-utils:
<https://github.com/stlink-org/stlink/blob/develop/doc/tutorial.md#using-the-gdb-server>

# Support

Currently, the toolchain has been tested on the following devices and development boards:
* WeAct V3.0 (STM32F401CCU6)
* NUCLEO32-L031K6 (STM32L031K6)
* NUCLEO32-G431KB (STM32G431KB)

# Participating

Please feel free open issues and pull-requests on the project. My personal number of development
boards is just limitteted. So if you have different boards and proved a cross-compilation file
or even more examples, do not hesitate to make them available!

The possibly available nucleo-platforms are listed here:
<https://www.st.com/en/evaluation-tools/stm32-nucleo-boards.html>

The repository is available here:
<https://github.com/amibranch/stm32_meson_blinky.git>

