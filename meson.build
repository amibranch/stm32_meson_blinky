project('stm32blinky', 'c', 'cpp',
  license : 'LGPL2.1+',
  default_options : [
    #'werror=true',
    'warning_level=3',
    'buildtype=minsize',
    'b_lto=true',
    'c_std=gnu99',
    'cpp_std=gnu++11',
    'b_ndebug=if-release',
    'b_staticpic=false',
    ],
  )

if get_option('buildtype')=='debugoptimized'
  # Even more debugging
  add_project_arguments('-g3', language: 'c')
endif

cc = meson.get_compiler('c')

subdir('src')
