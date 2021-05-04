cmake_minimum_required(VERSION 3.19.8 FATAL_ERROR)

set (PROJECT_NAME BattolCity)
project (${PROJECT_NAME})


add_executable(${PROJECT_NAME} 
исходник/main.cpp
   исходник/Рендор/ШейдернаяПрограмма.cpp
    исходник/Рендор/ШейдернаяПрограмма.h
	исходник/Ресерсы/РесурсныйМенеджер.cpp
	исходник/Ресерсы/РесурсныйМенеджер.h
	исходник/Ресерсы/stb_image.h
	
	)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17) 


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory (внешний/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory (внешний/glad)
target_link_libraries(${PROJECT_NAME} glad)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/создать/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory 
					${CMAKE_SOURCE_DIR}/ресерсы $<TARGET_FILE_DIR:${PROJECT_NAME}>/ресерсы)