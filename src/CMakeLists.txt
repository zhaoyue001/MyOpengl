
add_executable(test main.cpp buffer.cpp shader.cpp texture.cpp program.cpp device.cpp utils/fileReader.cpp utils/imageReader.cpp glad.c)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/include)
#target_link_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/lib)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(/usr/include/)
include_directories(${GLFW_INCLUDE_DIRS})
link_directories(${GLFW_LIBRARY_DIRS})
target_link_libraries(test ${GLFW_LIBRARIES})