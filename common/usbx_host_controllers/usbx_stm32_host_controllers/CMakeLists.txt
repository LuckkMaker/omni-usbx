file(GLOB SOURCES)

if(CONFIG_UX_HOST_CONTROLLER)
    list(APPEND SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_callback.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_controller_disable.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_ed_obtain.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_endpoint_create.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_endpoint_destroy.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_endpoint_reset.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_entry.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_frame_number_get.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_initialize.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_interrupt_handler.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_least_traffic_list_get.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_periodic_schedule.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_port_disable.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_port_enable.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_port_reset.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_port_resume.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_port_status_get.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_port_suspend.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_power_down_port.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_power_on_port.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_request_bulk_transfer.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_request_control_transfer.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_request_periodic_transfer.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_request_trans_finish.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_request_trans_prepare.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_request_transfer.c
    ${CMAKE_CURRENT_LIST_DIR}/ux_hcd_stm32_transfer_abort.c
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