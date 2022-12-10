
add_executable(test main.cpp  shader.cpp program.cpp utils/fileReader.cpp glad.c)
target_include_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_directories(test PRIVATE ${PROJECT_SOURCE_DIR}/lib)
target_link_libraries(test glfw3)