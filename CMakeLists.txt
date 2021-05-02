cmake_minimum_required(VERSION 3.19.8 FATAL_ERROR)

set (PROGRAM_NAME BattolCity)
project (${PROGRAM_NAME})

set(CMAKE_CXX_STANDARD 19)

add_executable(${PROGRAM_NAME} исходник/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory (внешний/glfw)
target_link_libraries(${PROGRAM_NAME} glfw)

add_subdirectory (внешний/glad)
target_link_libraries(${PROGRAM_NAME} glad)