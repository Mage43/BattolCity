cmake_minimum_required(VERSION 3.19.8 FATAL_ERROR)

set (PROJECT_NAME BattolCity)
project (${PROJECT_NAME})


add_executable(${PROJECT_NAME} 
исходник/main.cpp
        исходник/Рендор/ШейдернаяПрограмма.cpp
        исходник/Рендор/ШейдернаяПрограмма.h
	исходник/Рендор/Текстуры2D.cpp
	исходник/Рендор/Текстуры2D.h
        исходник/Рендор/Спрайт.cpp
        исходник/Рендор/Спрайт.h
        исходник/Рендор/ВекторБуффер.cpp
        исходник/Рендор/ВекторБуффер.h
        исходник/Рендор/ИндексБуффер.cpp
        исходник/Рендор/ИндексБуффер.h
        исходник/Рендор/ВекторМножество.cpp
        исходник/Рендор/ВекторМножество.h
        исходник/Рендор/РасположениеВекторБуфера.cpp
        исходник/Рендор/РасположениеВекторБуфера.h
        исходник/Рендор/АнимацияСпрайт.cpp
	исходник/Рендор/АнимацияСпрайт.h
        исходник/Рендор/Рендор.cpp
        исходник/Рендор/Рендор.h

        исходник/Ресерсы/РесурсныйМенеджер.cpp
	исходник/Ресерсы/РесурсныйМенеджер.h
	исходник/Ресерсы/stb_image.h

	исходник/Игра/Игра.cpp
	исходник/Игра/Игра.h
	исходник/Игра/Танк.cpp
	исходник/Игра/Танк.h
       

	)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17) 


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory (внешний/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

include_directories(внешний/glm)


include_directories(внешний/rapidjson/include)

add_subdirectory (внешний/glad)
target_link_libraries(${PROJECT_NAME} glad)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/создать/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_directory 
					${CMAKE_SOURCE_DIR}/ресерсы $<TARGET_FILE_DIR:${PROJECT_NAME}>/ресерсы)