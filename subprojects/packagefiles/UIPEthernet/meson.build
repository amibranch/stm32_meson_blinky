project('UIPEthernet', 'c', 'cpp',
  version : '2.0.12',
  license : 'LGPL2.1+',
  default_options : [
    'werror=false',
    'warning_level=0',
    'c_std=gnu11',
    'cpp_std=gnu++11',
    'buildtype=minsize',
    'b_lto=true',
    'b_staticpic=false',
    ],
  )
assert(meson.is_cross_build(),
       'Arduino projects can only be built in a cross build environment.')

# whether install definitions are added (not when compiling as subproject)
do_install = not meson.is_subproject()

arduino_core = subproject('ArduinoCore-avr')
ardu_inc = arduino_core.get_variable('includes')
ardu_lib = arduino_core.get_variable('arduinocore_main_lib')
ardu_dep = arduino_core.get_variable('arduinocore_main_dep')

uipethernet_src = files([
    'Dhcp.cpp',
    'Dns.cpp',
    'UIPClient.cpp',
    'UIPEthernet.cpp',
    'UIPServer.cpp',
    'UIPUdp.cpp',
    #'utility/clock-arch.cpp',
    'utility/Enc28J60Network.cpp',
    'utility/mempool.cpp',
    'utility/uip.c',
    'utility/uip_arp.c',
    #'utility/uip_debug.cpp',
    #'utility/uip_timer.c',
  ])
uipethernet_inc = ['.', 'utility']

includes = include_directories([uipethernet_inc])

uipethernet_lib = static_library(
  'uipethernet', uipethernet_src,
  cpp_args : ['-w',
#              '-Wall',
#              '-Wextra',
#              '-D_Float128=double',
               '-Os',
              ],
  link_with : ardu_lib,
  include_directories : [includes, ardu_inc],
  link_depends : ardu_lib,
  dependencies : ardu_dep,
  install : do_install,
  install_dir : 'lib/avr/lib'
)

uipethernet_dep = declare_dependency(
  include_directories : [includes],
  link_with : uipethernet_lib)

if do_install
  uipethernet_header = files([
    'Dhcp.h',
    'Dns.h',
    'ethernet_comp.h',
    'UIPClient.h',
    'UIPEthernet.h',
    'UIPServer.h',
    'UIPUdp.h',
    'utility/clock-arch.h',
    'utility/enc28j60.h',
    'utility/Enc28J60Network.h',
    'utility/logging.h',
    'utility/mempool.h',
    'utility/mempool_conf.h',
    'utility/uip.h',
    'utility/uip_arch.h',
    'utility/uip_arp.h',
    'utility/uip_clock.h',
    'utility/uip-conf.h',
    'utility/uip_debug.h',
    'utility/uipethernet-conf.h',
    'utility/uipopt.h',
    'utility/uip_timer.h',
    ])
  install_headers(uipethernet_header, install_dir: 'lib/avr/include/uipethernet')
endif
