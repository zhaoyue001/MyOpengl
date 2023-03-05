add_executable(test
               main.cpp
               buffer.cpp
               shader.cpp
               texture.cpp
               program.cpp
               device.cpp
               utils/fileReader.cpp
               utils/imageReader.cpp
               glad.c)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(test PRIVATE ${CMAKE_BINARY_DIR})
if(WIN32)
    target_link_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/lib)
    target_link_libraries(test glfw3)
else()
    find_package(glfw3 REQUIRED)
    target_link_libraries(test glfw)
endif()