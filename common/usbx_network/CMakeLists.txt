file(GLOB SOURCES)

if(CONFIG_UX_NETWORK_DRIVER)
    list(APPEND SOURCES 
    ${CMAKE_CURRENT_LIST_DIR}/src/ux_network_driver.c
    )
endif()

target_sources(omni-usbx INTERFACE
    # {{BEGIN_TARGET_SOURCES}}
    ${SOURCES}

    # {{END_TARGET_SOURCES}}
)

target_include_directories(omni-usbx INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/inc
)
