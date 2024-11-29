## __BLE_GATT_caching_Client Application Description__

Demonstrate STM32WBA acting as BLE central and GATT client.

BLE_GATT_caching_Client application scans and connects to BLE_GATT_caching_Server device.

Both devices support GATT caching feature.
The client stores the discovered attribute handles and Database Hash value. 
Purpose is to show the use of the Database Hash value and the use of Robust Caching in Client Supported Feature characteristic.


### __Keywords__

Connectivity, BLE, BLE protocol, BLE pairing, BLE GATT caching, BLE profile


### __Directory contents__

  - BLE_GATT_caching_Client/Core/Inc/app_common.h                                 App Common application configuration file for STM32WPAN Middleware. 
  - BLE_GATT_caching_Client/Core/Inc/app_conf.h                                   Application configuration file for STM32WPAN Middleware. 
  - BLE_GATT_caching_Client/Core/Inc/app_entry.h                                  Interface to the application 
  - BLE_GATT_caching_Client/Core/Inc/main.h                                       Header for main.c file. This file contains the common defines of the application.
  - BLE_GATT_caching_Client/Core/Inc/stm32wbaxx_hal_conf.h                        HAL configuration file. 
  - BLE_GATT_caching_Client/Core/Inc/stm32wbaxx_it.h                              This file contains the headers of the interrupt handlers. 
  - BLE_GATT_caching_Client/Core/Inc/stm32wbaxx_nucleo_conf.h                     STM32WBAXX nucleo board configuration file. This file should be copied to the application folder and renamed
to stm32wbaxx_nucleo_conf.h .
  - BLE_GATT_caching_Client/Core/Inc/utilities_conf.h                             Header for configuration file for STM32 Utilities. 
  - BLE_GATT_caching_Client/STM32_WPAN/App/app_ble.h                              Header for ble application 
  - BLE_GATT_caching_Client/STM32_WPAN/App/ble_conf.h                             Configuration file for BLE Middleware. 
  - BLE_GATT_caching_Client/STM32_WPAN/App/ble_dbg_conf.h                         Debug configuration file for BLE Middleware. 
  - BLE_GATT_caching_Client/STM32_WPAN/App/gatt_client_app.h                      Header for gatt_client_app.c module 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/bpka.h                              This file contains the interface of the BLE PKA module. 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/host_stack_if.h                     This file contains the interface for the stack tasks 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/ll_sys_if.h                         Header file for ll_sys_if.c  
  - BLE_GATT_caching_Client/System/Config/ADC_Ctrl/adc_ctrl_conf.h                Configuration Header for ADC controller module 
  - BLE_GATT_caching_Client/System/Config/CRC_Ctrl/crc_ctrl_conf.h                Configuration Header for CRC controller module 
  - BLE_GATT_caching_Client/System/Config/Debug_GPIO/app_debug.h                  Real Time Debug module application APIs and signal table 
  - BLE_GATT_caching_Client/System/Config/Debug_GPIO/app_debug_signal_def.h       Real Time Debug module application signal definition 
  - BLE_GATT_caching_Client/System/Config/Debug_GPIO/debug_config.h               Real Time Debug module general configuration file 
  - BLE_GATT_caching_Client/System/Config/Flash/simple_nvm_arbiter_conf.h         Configuration header for simple_nvm_arbiter.c module 
  - BLE_GATT_caching_Client/System/Config/Log/log_module.h                        Configuration Header for log module 
  - BLE_GATT_caching_Client/System/Config/LowPower/app_sys.h                      Header for app_sys.c 
  - BLE_GATT_caching_Client/System/Config/LowPower/peripheral_init.h              Header for peripheral init module 
  - BLE_GATT_caching_Client/System/Config/LowPower/user_low_power_config.h        Header for user_low_power_config.c
  - BLE_GATT_caching_Client/System/Interfaces/hw.h                                This file contains the interface of STM32 HW drivers. 
  - BLE_GATT_caching_Client/System/Interfaces/hw_if.h                             Hardware Interface 
  - BLE_GATT_caching_Client/System/Interfaces/stm32_lpm_if.h                      Header for stm32_lpm_if.c module (device specific LP management) 
  - BLE_GATT_caching_Client/System/Interfaces/timer_if.h                          configuration of the timer_if.c instances 
  - BLE_GATT_caching_Client/System/Interfaces/usart_if.h                          Header file for stm32_adv_trace interface file 
  - BLE_GATT_caching_Client/System/Modules/adc_ctrl.h                             Header for ADC client manager module 
  - BLE_GATT_caching_Client/System/Modules/ble_timer.h                            This header defines the timer functions used by the BLE stack 
  - BLE_GATT_caching_Client/System/Modules/crc_ctrl.h                             Header for CRC client manager module
  - BLE_GATT_caching_Client/System/Modules/dbg_trace.h                            Header for dbg_trace.c 
  - BLE_GATT_caching_Client/System/Modules/otp.h                                  Header file for One Time Programmable (OTP) area 
  - BLE_GATT_caching_Client/System/Modules/scm.h                                  Header for scm.c module 
  - BLE_GATT_caching_Client/System/Modules/stm_list.h                             Header file for linked list library. 
  - BLE_GATT_caching_Client/System/Modules/temp_measurement.h                     Header file for temperature measurement module
  - BLE_GATT_caching_Client/System/Modules/utilities_common.h                     Common file to utilities 
  - BLE_GATT_caching_Client/System/Modules/baes/baes.h                            This file contains the interface of the basic AES software module. 
  - BLE_GATT_caching_Client/System/Modules/baes/baes_global.h                     This file contains the internal definitions of the AES software module.
  - BLE_GATT_caching_Client/System/Modules/Flash/flash_driver.h                   Header for flash_driver.c module 
  - BLE_GATT_caching_Client/System/Modules/Flash/flash_manager.h                  Header for flash_manager.c module 
  - BLE_GATT_caching_Client/System/Modules/Flash/rf_timing_synchro.h              Header for rf_timing_synchro.c module 
  - BLE_GATT_caching_Client/System/Modules/Flash/simple_nvm_arbiter.h             Header for simple_nvm_arbiter.c module 
  - BLE_GATT_caching_Client/System/Modules/Flash/simple_nvm_arbiter_common.h      Common header of simple_nvm_arbiter.c module 
  - BLE_GATT_caching_Client/System/Modules/MemoryManager/advanced_memory_manager.h Header for advance_memory_manager.c module 
  - BLE_GATT_caching_Client/System/Modules/MemoryManager/stm32_mm.h               Header for stm32_mm.c module 
  - BLE_GATT_caching_Client/System/Modules/Nvm/nvm.h                              This file contains the interface of the NVM manager. 
  - BLE_GATT_caching_Client/System/Modules/RFControl/rf_antenna_switch.h          RF related module to handle dedictated GPIOs for antenna switch
  - BLE_GATT_caching_Client/System/Modules/RTDebug/debug_signals.h                Real Time Debug module System and Link Layer signal definition 
  - BLE_GATT_caching_Client/System/Modules/RTDebug/local_debug_tables.h           Real Time Debug module System and Link Layer signal 
  - BLE_GATT_caching_Client/System/Modules/RTDebug/RTDebug.h                      Real Time Debug module API declaration 
  - BLE_GATT_caching_Client/System/Modules/RTDebug/RTDebug_dtb.h                  Real Time Debug module API declaration for DTB usage
  - BLE_GATT_caching_Client/System/Modules/SerialCmdInterpreter/serial_cmd_interpreter.h         Header file for the serial commands interpreter module
  - BLE_GATT_caching_Client/Core/Src/app_entry.c                                  Entry point of the application 
  - BLE_GATT_caching_Client/Core/Src/main.c                                       Main program body 
  - BLE_GATT_caching_Client/Core/Src/stm32wbaxx_hal_msp.c                         This file provides code for the MSP Initialization and de-Initialization codes.
  - BLE_GATT_caching_Client/Core/Src/stm32wbaxx_it.c                              Interrupt Service Routines. 
  - BLE_GATT_caching_Client/Core/Src/system_stm32wbaxx.c                          CMSIS Cortex-M33 Device Peripheral Access Layer System Source File 
  - BLE_GATT_caching_Client/STM32_WPAN/App/app_ble.c                              BLE Application 
  - BLE_GATT_caching_Client/STM32_WPAN/App/gatt_client_app.c                      GATT Client Application 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/bleplat.c                           This file implements the platform functions for BLE stack library. 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/bpka.c                              This file implements the BLE PKA module. 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/host_stack_if.c                     Source file for the stack tasks 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/linklayer_plat.c                    Source file for the linklayer plateform adaptation layer 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/ll_sys_if.c                         Source file for initiating the system sequencer 
  - BLE_GATT_caching_Client/STM32_WPAN/Target/power_table.c                       This file contains supported power tables 
  - BLE_GATT_caching_Client/System/Config/ADC_Ctrl/adc_ctrl_conf.c                Source for ADC client controller module configuration file 
  - BLE_GATT_caching_Client/System/Config/CRC_Ctrl/crc_ctrl_conf.c                Source for CRC client controller module configuration file 
  - BLE_GATT_caching_Client/System/Config/Debug_GPIO/app_debug.c                  Real Time Debug module application side APIs 
  - BLE_GATT_caching_Client/System/Config/Log/log_module.c                        Source file of the log module 
  - BLE_GATT_caching_Client/System/Config/LowPower/user_low_power_config.c        Low power related user configuration
  - BLE_GATT_caching_Client/System/Config/LowPower/peripheral_init.c              Source for peripheral init module
  - BLE_GATT_caching_Client/System/Interfaces/hw_aes.c                            This file contains the AES driver for STM32WBA 
  - BLE_GATT_caching_Client/System/Interfaces/hw_otp.c                            This file contains the OTP driver. 
  - BLE_GATT_caching_Client/System/Interfaces/hw_pka.c                            This file contains the PKA driver for STM32WBA 
  - BLE_GATT_caching_Client/System/Interfaces/hw_rng.c                            This file contains the RNG driver for STM32WBA 
  - BLE_GATT_caching_Client/System/Interfaces/pka_p256.c                          This file is an optional part of the PKA driver for STM32WBA. It is dedicated to the P256 elliptic curve.
  - BLE_GATT_caching_Client/System/Interfaces/stm32_lpm_if.c                      Low layer function to enter/exit low power modes (stop, sleep) 
  - BLE_GATT_caching_Client/System/Interfaces/timer_if.c                          Configure RTC Alarm, Tick and Calendar manager 
  - BLE_GATT_caching_Client/System/Interfaces/usart_if.c                          Source file for interfacing the stm32_adv_trace to hardware 
  - BLE_GATT_caching_Client/System/Modules/adc_ctrl.c                             Header for ADC client manager module 
  - BLE_GATT_caching_Client/System/Modules/app_sys.c                              Application system for STM32WPAN Middleware. 
  - BLE_GATT_caching_Client/System/Modules/ble_timer.c                            This module implements the timer core functions 
  - BLE_GATT_caching_Client/System/Modules/crc_ctrl.c                             Source for CRC client controller module
  - BLE_GATT_caching_Client/System/Modules/otp.c                                  Source file for One Time Programmable (OTP) area 
  - BLE_GATT_caching_Client/System/Modules/scm.c                                  Functions for the System Clock Manager. 
  - BLE_GATT_caching_Client/System/Modules/stm_list.c                             TCircular Linked List Implementation. 
  - BLE_GATT_caching_Client/System/Modules/temp_measurement.c                     Temperature measurement module
  - BLE_GATT_caching_Client/System/Modules/baes/baes_cmac.c                       This file contains the AES CMAC implementation. 
  - BLE_GATT_caching_Client/System/Modules/baes/baes_ecb.c                        This file contains the AES ECB functions implementation. 
  - BLE_GATT_caching_Client/System/Modules/Flash/flash_driver.c                   The Flash Driver module is the interface layer between Flash management modules and HAL Flash drivers
  - BLE_GATT_caching_Client/System/Modules/Flash/flash_manager.c                  The Flash Manager module provides an interface to write raw data from SRAM to FLASH
  - BLE_GATT_caching_Client/System/Modules/Flash/rf_timing_synchro.c              The RF Timing Synchronization module provides an interface to synchronize the flash processing versus the RF activity to make
sure the RF timing is not broken
  - BLE_GATT_caching_Client/System/Modules/Flash/simple_nvm_arbiter.c             The Simple NVM arbiter module provides an interface to write and/or restore data from SRAM to FLASH with use of NVMs.
  - BLE_GATT_caching_Client/System/Modules/MemoryManager/advanced_memory_manager.c Memory Manager 
  - BLE_GATT_caching_Client/System/Modules/MemoryManager/stm32_mm.c               Memory Manager
  - BLE_GATT_caching_Client/System/Modules/Nvm/nvm_emul.c                         This file implements the RAM version of the NVM manager for STM32WBX. It is made for test purpose.
  - BLE_GATT_caching_Client/System/Modules/RFControl/rf_antenna_switch.c          RF related module to handle dedictated GPIOs for antenna switch
  - BLE_GATT_caching_Client/System/Modules/RTDebug/RTDebug.c                      Real Time Debug module API definition 
  - BLE_GATT_caching_Client/System/Modules/RTDebug/RTDebug_dtb.c                  Real Time Debug module API definition for DTB usage
  - BLE_GATT_caching_Client/System/Modules/SerialCmdInterpreter/serial_cmd_interpreter.c         Source file for the serial commands interpreter module 

### __Hardware and Software environment__

  - This example runs on STM32WBA55xx devices.
    Connect the Nucleo Board to your PC with a USB cable type A to mini-B to ST-LINK connector (USB_STLINK).


### __How to use it?__

In order to make the program work, you must do the following:

 - Open IAR toolchain 
 - Rebuild all files and flash the board with the executable file. 

__Use of two nucleo boards__ 

Two STM32WBA55xx nucleo boards are used, one central/client (flashed with BLE_GATT_caching_Client) and one peripheral/server (flashed with BLE_GATT_caching_Server). 

The GATT server and GATT client boards support GATT caching feature, two new characteristics are automatically added to the generic attribute service, Database Hash and Client Supported Feature.

The board flashed with BLE_GATT_caching_Client is defined as GAP central.

Open a VT100 terminal on Central and Peripheral side (ST Link Com Port, @115200 bauds).

At reset application initialization is done.

 - The peripheral device starts advertising.

 Database Hash characteristic example:

 - Push B1 on central: the central device scans and automatically connects to the peripheral (use of FW_ID_GC_SERVER). 
 After connection:
 - Discovery of service and characteristics.
 - Stores the discovered attribute handles and Database Hash value.

On server side when connected, and after Client service and characteristics discoveries:
 - Push B2: delete of characteristic 3, new value of Database Hash.

On client:
 - Push B2: disconnection request
 - Push B1: scan is started, client checks if the Database Hash value has changed.
 If it has changed, client restarts a database discovery, stores new attribute handles and Hash value.
  
Client Supported Feature characteristic example:

 - Push B1 on central: the central device scans and automatically connects to the peripheral (use of FW_ID_GC_SERVER).
 After connection: 
 - Discovery of service and characteristics.
 - Stores the discovered attribute handles and Database Hash value.
 - Enables Robust Caching (set "robust caching" bit in Client Supported Feature characteristic)

On client:
 - Push B3: read characteristic 2 value 

On server side when connected, and after Client service and characteristics discoveries:
 - Push B2: delete of characteristic 3.

On client:
 - Push B3: read characteristic 2 value: server sends a "Database out-of-sync"error. Client becomes "change aware" from server perspective.
 - Push B3: read characteristic 2 value, ok.


