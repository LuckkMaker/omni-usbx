file(GLOB SOURCES)

if(CONFIG_UX_DEVICE_CONTROLLER)
    list(APPEND SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_callback.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_endpoint_create.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_endpoint_destroy.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_endpoint_reset.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_endpoint_stall.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_endpoint_status.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_frame_number_get.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_function.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_initialize_complete.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_initialize.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_interrupt_handler.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_transfer_abort.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_transfer_request.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_transfer_run.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_dcd_stm32_uninitialize.c
    )
endif()

target_sources(omni-usbx INTERFACE
    # {{BEGIN_TARGET_SOURCES}}
    ${SOURCES}

    # {{END_TARGET_SOURCES}}
)

target_include_directories(omni-usbx INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)