project('cmsis_core', 'c', 'cpp',
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

cmsis_core_headers = [
  'Include/cmsis_armcc.h',
  'Include/cmsis_armclang.h',
  'Include/cmsis_armclang_ltm.h',
  'Include/cmsis_compiler.h',
  'Include/cmsis_gcc.h',
  'Include/cmsis_iccarm.h',
  'Include/cmsis_version.h',
  'Include/core_armv81mml.h',
  'Include/core_armv8mbl.h',
  'Include/core_armv8mml.h',
  'Include/core_cm0.h',
  'Include/core_cm0plus.h',
  'Include/core_cm1.h',
  'Include/core_cm23.h',
  'Include/core_cm33.h',
  'Include/core_cm35p.h',
  'Include/core_cm3.h',
  'Include/core_cm4.h',
  'Include/core_cm7.h',
  'Include/core_sc000.h',
  'Include/core_sc300.h',
  'Include/mpu_armv7.h',
  'Include/mpu_armv8.h',
  'Include/tz_context.h',
  ]

cmsis_core_dep = declare_dependency(
    include_directories: ['.', 'Include'],
    sources: cmsis_core_headers,
  )

