cmake_minimum_required(VERSION 3.13)
PROJECT(MyOpengl)

set(SHADERS_PATH ${PROJECT_SOURCE_DIR}/shaders)
set(RESOURCE_PATH ${PROJECT_SOURCE_DIR}/resource)

configure_file(./src/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/config.h @ONLY)
add_subdirectory(src)