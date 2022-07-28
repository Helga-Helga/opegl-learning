cmake_minimum_required(VERSION 3.10)

project(SimpleTriangle)

add_executable(SimpleTriangle simple_triangle.cpp)

find_package(glfw3 3.2 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(SimpleTriangle glfw)
target_link_libraries(SimpleTriangle OpenGL::GL)
