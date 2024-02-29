
assert(meson.is_cross_build(), 'This project can only be built in a cross build environment.')

stmfam = meson.get_external_property('stm32family')
stmsubfam = meson.get_external_property('stm32subfamily')

platform_link_args = []
platform_c_args = []

if stmfam == 'l0'
  hal_driver_subp = 'stm32l0xx_hal_driver'
  cmsis_dev_subp = 'cmsis_device_l0'
  linker_script = join_paths(meson.current_source_dir(), 'linkerscripts', 'stm32l0xx_flash.ld')
elif stmfam == 'f4'
  hal_driver_subp = 'stm32f4xx_hal_driver'
  cmsis_dev_subp = 'cmsis_device_f4'
  linker_script = join_paths(meson.current_source_dir(), 'linkerscripts', 'stm32f40xx_flash.ld')
  platform_link_args += [
    '-mfloat-abi=hard',
    '-mthumb',
    ]
  platform_c_args += [
    '-mfloat-abi=hard',
    '-mthumb',
    ]
elif stmfam == 'g4'
  hal_driver_subp = 'stm32g4xx_hal_driver'
  cmsis_dev_subp = 'cmsis_device_g4'
  linker_script = join_paths(meson.current_source_dir(), 'linkerscripts', 'STM32G431RBTX_FLASH.ld')
  platform_link_args += [
    '-mfloat-abi=hard',
    '-mthumb',
    ]
  platform_c_args += [
    '-mfloat-abi=hard',
    '-mthumb',
    ]
endif

stm32_hal = subproject(hal_driver_subp)
stm32_hal_dep = stm32_hal.get_variable('stm32_hal_dep')

cmsis_device = subproject(cmsis_dev_subp)
cmsis_device_dep = cmsis_device.get_variable('cmsis_device_dep')

cmsis_core = subproject('cmsis_core')
cmsis_core_dep = cmsis_core.get_variable('cmsis_core_dep')

exe = executable('main.elf', ['main.c' ],
  c_args : [
    '-DUSE_FULL_LL_DRIVER',
    '-DUSE_HAL_DRIVER',
    '-mcpu=@0@'.format(target_machine.cpu()), '-mfpu=fpv4-sp-d16', '-specs=nano.specs',
    '--include=stm32@0@.h'.format(stmsubfam),
    ] + platform_c_args,
  extra_files: [ linker_script, ],
  link_args : [
    '-lm', '-lc', '-lnosys',
    '-mcpu=@0@'.format(target_machine.cpu()), '-mfpu=fpv4-sp-d16',
    '-specs=nano.specs',
    '-T' + linker_script,
    ] + platform_link_args,
  dependencies : [
    stm32_hal_dep, cmsis_core_dep, cmsis_device_dep,
    ],
)

objcopy = find_program('objcopy')

eep = custom_target('main.eep',
  input : exe,
  output : 'main.eep',
  command : [objcopy, '-O', 'ihex', '-j', '.eeprom',
    '--set-section-flags=.eeprom=alloc,load',
    '--no-change-warnings', '--change-section-lma',
    '.eeprom=0', '@INPUT@', '@OUTPUT@',
  ]
)

hex = custom_target('main.hex',
  input : exe,
  output : 'main.hex',
  command : [objcopy, '-O', 'ihex', # '-R', '.eeprom',
    '@INPUT@', '@OUTPUT@',
  ],
  build_by_default : true,
)

hex = custom_target('main.bin',
  input : exe,
  output : 'main.bin',
  command : [objcopy, '-O', 'binary', '-S', # '-R', '.eeprom',
    '@INPUT@', '@OUTPUT@',
  ],
  build_by_default : true,
)

flash = run_target('flash',
  command : [
    'st-flash', '--reset', 'write',
    hex,
    '0x8000000',
  ],
  depends : hex,
)

