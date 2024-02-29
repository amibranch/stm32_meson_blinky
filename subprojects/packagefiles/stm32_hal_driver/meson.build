project('stm32_hal_driver', 'c', 'cpp',
  license : 'BSD3',
  version: '@0@.@1@.@2@'.format(
    run_command('git', 'describe',  '--tags', '--always', check: true).stdout().strip().strip('v').split('.')[0],
    run_command('git', 'describe',  '--tags', '--always', check: true).stdout().strip().split('.')[1],
    run_command('git', 'describe',  '--tags', '--always', check: true).stdout().strip().split('.')[2],
    ),
  default_options : [
    'werror=false',
    'warning_level=3',
    'b_lto=true',
    'c_std=gnu99',
    'cpp_std=gnu++11',
    'b_ndebug=if-release',
    'b_staticpic=false',
    ],
  )

dev_family = meson.get_external_property('stm32family')
dev_subfamily = meson.get_external_property('stm32subfamily')
dev_variant = meson.get_external_property('variant')

# FIXME: Make modules dynamic!

stm32_hal_sources = []
stm32_hal_sources += [
    #'Src/stm32@0@_hal_ltdc.c',
    'Src/stm32@0@_hal_cortex.c'.format(dev_subfamily),
    #'Src/stm32@0@_hal_crc.c',
    #'Src/stm32@0@_hal_fmpsmbus_ex.c',
    #'Src/stm32@0@_ll_usb.c',
    'Src/stm32@0@_hal_rtc.c'.format(dev_subfamily),
    #'Src/stm32@0@_ll_utils.c',
    #'Src/stm32@0@_hal_dcmi_ex.c',
    #'Src/stm32@0@_hal_qspi.c',
    'Src/stm32@0@_hal_gpio.c'.format(dev_subfamily),
    #'Src/stm32@0@_hal_pcd.c',
    #'Src/stm32@0@_hal_hash_ex.c',
    #'Src/stm32@0@_hal_hcd.c',
    #'Src/stm32@0@_hal_dac_ex.c',
    #'Src/stm32@0@_ll_dma.c',
    #'Src/stm32@0@_hal_sai_ex.c',
    #'Src/stm32@0@_hal_eth.c',
    #'Src/stm32@0@_hal_nand.c',
    #'Src/stm32@0@_hal_adc.c',
    #'Src/stm32@0@_hal_can.c',
    #'Src/stm32@0@_hal_cryp_ex.c',
    #'Src/stm32@0@_ll_adc.c',
    #'Src/stm32@0@_hal_i2s_ex.c',
    #'Src/stm32@0@_hal_sram.c',
    #'Src/stm32@0@_ll_exti.c',
    'Src/stm32@0@_hal.c'.format(dev_subfamily),
    'Src/stm32@0@_hal_rcc.c'.format(dev_subfamily),
    'Src/stm32@0@_ll_rcc.c'.format(dev_subfamily),
    'Src/stm32@0@_ll_gpio.c'.format(dev_subfamily),
    #'Src/stm32@0@_hal_hash.c',
    #'Src/stm32@0@_hal_spi.c',
    #'Src/stm32@0@_hal_sdram.c',
    #'Src/stm32@0@_ll_spi.c',
    'Src/stm32@0@_hal_pwr.c'.format(dev_subfamily),
    #'Src/stm32@0@_hal_dcmi.c',
    #'Src/stm32@0@_hal_ltdc_ex.c',
    #'Src/stm32@0@_hal_dma2d.c',
    #'Src/stm32@0@_hal_fmpi2c.c',
    #'Src/stm32@0@_hal_flash.c',
    #'Src/stm32@0@_ll_sdmmc.c',
    #'Src/stm32@0@_ll_tim.c',
    #'Src/stm32@0@_hal_smbus.c',
    #'Src/stm32@0@_hal_flash_ramfunc.c',
    #'Src/stm32@0@_hal_tim.c',
    #'Src/stm32@0@_hal_i2c.c',
    #'Src/stm32@0@_ll_usart.c',
    #'Src/stm32@0@_hal_exti.c',
    #'Src/stm32@0@_hal_wwdg.c',
    #'Src/stm32@0@_ll_dac.c',
    #'Src/stm32@0@_ll_fsmc.c',
    #'Src/stm32@0@_hal_fmpsmbus.c',
    'Src/stm32@0@_hal_dma.c'.format(dev_subfamily),
    #'Src/stm32@0@_hal_usart.c',
    #'Src/stm32@0@_hal_pccard.c',
    #'Src/stm32@0@_hal_cryp.c',
    #'Src/stm32@0@_hal_dac.c',
    #'Src/stm32@0@_hal_iwdg.c',
    #'Src/stm32@0@_hal_dma_ex.c',
    #'Src/stm32@0@_hal_dfsdm.c',
    #'Src/stm32@0@_hal_sd.c',
    'Src/stm32@0@_hal_rcc_ex.c'.format(dev_subfamily),
    #'Src/stm32@0@_ll_fmpi2c.c',
    #'Src/stm32@0@_hal_pcd_ex.c',
    #'Src/stm32@0@_ll_i2c.c',
    #'Src/Legacy/stm32@0@_hal_eth.c',
    #'Src/Legacy/stm32@0@_hal_can.c',
    #'Src/stm32@0@_hal_adc_ex.c',
    #'Src/stm32@0@_ll_rng.c',
    #'Src/stm32@0@_hal_irda.c',
    #'Src/stm32@0@_hal_dsi.c',
    #'Src/stm32@0@_ll_fmc.c',
    #'Src/stm32@0@_hal_tim_ex.c',
    #'Src/stm32@0@_hal_flash_ex.c',
    #'Src/stm32@0@_hal_rng.c',
    #'Src/stm32@0@_hal_uart.c',
    'Src/stm32@0@_ll_rtc.c'.format(dev_subfamily),
    #'Src/stm32@0@_ll_crc.c',
    #'Src/stm32@0@_hal_pwr_ex.c',
    #'Src/stm32@0@_hal_sai.c',
    #'Src/stm32@0@_hal_mmc.c',
    #'Src/stm32@0@_hal_nor.c',
    #'Src/stm32@0@_hal_smartcard.c',
    #'Src/stm32@0@_ll_pwr.c',
    #'Src/stm32@0@_hal_lptim.c',
    #'Src/stm32@0@_hal_i2s.c',
    #'Src/stm32@0@_hal_fmpi2c_ex.c',
    #'Src/stm32@0@_hal_cec.c',
    #'Src/stm32@0@_hal_i2c_ex.c',
    #'Src/stm32@0@_ll_lptim.c',
    #'Src/stm32@0@_hal_spdifrx.c',
    #'Src/stm32@0@_ll_dma2d.c',
    'Src/stm32@0@_hal_rtc_ex.c'.format(dev_subfamily),
  ]

stm32_hal_headers = []
header_list = [
    'll_system',
    'hal_i2c',
    'hal_cryp_ex',
    'll_i2c',
    'll_iwdg',
    'll_exti',
    'hal_iwdg',
    'hal_wwdg',
    'hal_crc',
    'hal_flash_ramfunc',
    'hal_smartcard',
    'hal_lptim',
    'll_tim',
    'll_pwr',
    'll_spi',
    'll_rcc',
    'hal_tim',
    'hal_rtc',
    'll_utils',
    'hal_pwr',
    'hal_tim_ex',
    'hal_uart',
    'hal_pcd_ex',
    'll_crc',
    'hal_cortex',
    'hal_flash',
    'hal_gpio_ex',
    'll_dac',
    'hal_adc_ex',
    'll_gpio',
    'hal_rcc',
    'hal_irda',
    'hal_usart',
    'hal_dma',
    'hal_gpio',
    'hal_exti',
    'hal_smbus',
    'hal_dac_ex',
    'll_dma',
    'hal_i2s',
    'll_rng',
    'hal_def',
    'll_lptim',
    'hal_flash_ex',
    'll_cortex',
    'hal_i2c_ex',
    'hal_adc',
    'll_rtc',
    'hal_rcc_ex',
    'hal_cryp',
    'hal_pcd',
    'll_usart',
    'hal_rng',
    'hal_pwr_ex',
    'll_bus',
    'll_adc',
    'll_wwdg',
    'hal_spi',
    'hal_rtc_ex',
    'll_usb',
    'hal',
    'hal_dac',
]

if dev_family == 'f4'
  header_list += [
    'hal_sai',
    'hal_spdifrx',
    'hal_mmc',
    'hal_eth',
    'hal_i2s_ex',
    'hal_sdram',
    'hal_sai_ex',
    'hal_dcmi',
    'hal_sram',
    'hal_nor',
    'll_sdmmc',
    'hal_pccard',
    'll_fsmc',
    'hal_ltdc_ex',
    'hal_hash_ex',
    'hal_fmpsmbus',
    'hal_dcmi_ex',
    'hal_qspi',
    'hal_can',
    'hal_dsi',
    'hal_cec',
    'hal_ltdc',
    'hal_fmpi2c',
    'hal_nand',
    'hal_hash',
    'hal_dma2d',
    'll_dma2d',
    'hal_hcd',
    'hal_sd',
    'll_fmpi2c',
    'hal_fmpsmbus_ex',
    'hal_fmpi2c_ex',
    'll_fmc',
    'hal_dfsdm',
    'hal_dma_ex',
  ]
  stm32_hal_headers += [
    'Inc/Legacy/stm32@0@_hal_can_legacy.h'.format(dev_subfamily),
    'Inc/Legacy/stm32@0@_hal_eth_legacy.h'.format(dev_subfamily),
  ]
endif


foreach header : header_list
  stm32_hal_headers += ['Inc/stm32@0@_@1@.h'.format(dev_subfamily, header)]
endforeach

stm32_hal_headers += [
    'Inc/Legacy/stm32_hal_legacy.h',
  ]

stm32_hal_gen_sources = []
stm32_hal_gen_sources += [
    configure_file(
        command: [
          'python3', join_paths(meson.current_source_dir(), 'hal_conf_template_configurator.py'),
          '-i', '@INPUT@', '-o', '@OUTPUT@',
          '-e', 'gpio', 'cortex', 'rtc', 'dma', 'rcc', 'pwr', 'flash', ],
        input: 'Inc/stm32@0@_hal_conf_template.h'.format(dev_subfamily),
        output: 'stm32@0@_hal_conf.h'.format(dev_subfamily),
      )]
stm32_hal_gen_sources += [
    configure_file(
        copy: true,
        input: 'Src/stm32@0@_hal_msp_template.c'.format(dev_subfamily),
        output: 'stm32@0@_hal_msp.c'.format(dev_subfamily),
      )]
stm32_hal_gen_sources += [
    configure_file(
        copy: true,
        input: 'Inc/stm32_assert_template.h',
        output: 'stm32_assert_template.h',
      )]

if dev_family == 'f4'
  stm32_hal_gen_sources += [
    configure_file(
        copy: true,
        input: 'Src/stm32@0@_hal_timebase_rtc_wakeup_template.c'.format(dev_subfamily),
        output: 'stm32@0@_hal_timebase.c'.format(dev_subfamily),
      )]
endif



stm32_hal_sources += stm32_hal_gen_sources

cmsis_core = subproject('cmsis_core')
cmsis_core_dep = cmsis_core.get_variable('cmsis_core_dep')
cmsis_device = subproject('cmsis_device_@0@'.format(dev_family))
cmsis_device_dep = cmsis_device.get_variable('cmsis_device_dep')

stm32_hal_lib = static_library(
  'hal_driver',
  stm32_hal_sources,
  c_args: [
      '-include', 'stdint.h',
      '-include', '@0@.h'.format(dev_variant),
      #'-D__CC_ARM',
      '-mcpu=@0@'.format(target_machine.cpu()),
      '-mthumb', '-mfpu=fpv4-sp-d16',
    ],
  dependencies: [
    cmsis_device_dep,
    cmsis_core_dep,
    ],
  include_directories: ['.', 'Inc', ],
  )

stm32_hal_dep = declare_dependency(
    include_directories: ['.', 'Inc', ],
    sources: stm32_hal_headers + stm32_hal_sources,
  )

