cmake_minimum_required(VERSION 3.2)
project(SDL_Demo)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -lmingw32 -liconv -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES sdl2game.h main.c)
add_executable(SDL_Demo ${SOURCE_FILES})

target_link_libraries(SDL_Demo iconv SDL2main SDL2 SDL2_image SDL2_mixer SDL2_ttf)
