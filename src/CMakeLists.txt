# This is the main binary. List your C files here.
add_executable(task_delay
    task_delay.c
)
add_executable(sleep
    sleep.c
)
add_executable(timer
    timer.c
)

pico_set_program_name(task_delay "Task Delay")
pico_set_program_version(task_delay "0.1")
pico_set_program_name(task_delay "Sleep")
pico_set_program_version(task_delay "0.1")
pico_set_program_name(task_delay "Timer")
pico_set_program_version(task_delay "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(task_delay 0)
pico_enable_stdio_usb(task_delay 1)
pico_enable_stdio_uart(sleep 0)
pico_enable_stdio_usb(sleep 1)
pico_enable_stdio_uart(timer 0)
pico_enable_stdio_usb(timer 1)

# Add the libraries to the build
target_link_libraries(task_delay PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)
target_link_libraries(sleep PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)
target_link_libraries(timer PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(task_delay PRIVATE
        pico_cyw43_arch_none
    )
    target_link_libraries(sleep PRIVATE
        pico_cyw43_arch_none
    )
    target_link_libraries(timer PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(task_delay)
pico_add_extra_outputs(sleep)
pico_add_extra_outputs(timer)

add_custom_target(flash picotool load -f $<TARGET_FILE:sleep> DEPENDS sleep)
