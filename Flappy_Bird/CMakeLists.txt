cmake_minimum_required(VERSION 3.2)
project(Flappy_Bird)
set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -lmingw32 -liconv -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf")
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
#[[复制素材文件]]
file(COPY asset/ DESTINATION ${CMAKE_BINARY_DIR})
file(COPY dll/ DESTINATION ${CMAKE_BINARY_DIR})

set(SOURCE_FILES main.c util.h queue.h)
add_executable(Flappy_Bird ${SOURCE_FILES})

target_link_libraries(Flappy_Bird iconv SDL2main SDL2 SDL2_image SDL2_mixer SDL2_ttf)
