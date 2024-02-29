project('cmsis_device', 'c', 'cpp',
  license : 'Apache-2.0',
  version: '@0@.@1@.@2@'.format(
    run_command('git', 'describe',  '--tags', '--always', check: true).stdout().strip().strip('v').split('.')[0],
    run_command('git', 'describe',  '--tags', '--always', check: true).stdout().strip().split('.')[1],
    run_command('git', 'describe',  '--tags', '--always', check: true).stdout().strip().split('.')[2],
    ),
  default_options : [
    'werror=true',
    'warning_level=3',
    'b_lto=true',
    'c_std=gnu99',
    'cpp_std=gnu++11',
    'b_ndebug=if-release',
    'b_staticpic=false',
    ],
  )

dev_subfamily = meson.get_external_property('stm32subfamily')
dev_variant = meson.get_external_property('variant')

# FIXME: figure out the other compilers (ARM, IAR) and support them automagically
if meson.get_compiler('c').get_id() != 'gcc'
  error('Startup-Scripts only available for GCC-based compilers/linkers!')
endif

cmsis_device_sources = [
    'Source/Templates/system_stm32@0@.c'.format(dev_subfamily),
    'Source/Templates/gcc/startup_@0@.s'.format(dev_variant),
  ]

cmsis_device_headers = [
    'Include/system_stm32@0@.h'.format(dev_subfamily),
    'Include/@0@.h'.format(dev_variant),
  ]

cmsis_device_dep = declare_dependency(
    include_directories: ['.', 'Include'],
    sources: cmsis_device_headers + cmsis_device_sources,
  )

