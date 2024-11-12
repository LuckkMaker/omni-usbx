# Copyright (c) 2024 LuckkMaker
# All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

add_library(omni-usbx INTERFACE)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/common)

# Add the USBX configuration file
set(USBX_CFG_SOURCE_FILE ${CMAKE_CURRENT_LIST_DIR}/common/core/inc/ux_user_sample.h)
set(USBX_CFG_TARGET_FILE ${OMNI_USB_CFG_DIR}/ux_user.h)
omni_add_configure_file(${USBX_CFG_SOURCE_FILE} ${USBX_CFG_TARGET_FILE})

target_compile_definitions(omni-usbx INTERFACE "UX_INCLUDE_USER_DEFINE_FILE" )

target_include_directories(omni-usbx INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/ports/generic/inc
)
