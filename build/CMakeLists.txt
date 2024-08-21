cmake_minimum_required(VERSION 3.10)
project(TetrisGame)

set(CMAKE_CXX_STANDARD 17)

# Find SDL2 and SDL2_gfx
find_package(SDL2 REQUIRED)
find_package(SDL2_gfx REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_gfx_INCLUDE_DIRS})

set(SOURCES
    src/IO.cpp
    src/Game.cpp
    src/Pieces.cpp
    src/Board.cpp
    src/main.cpp
)

add_executable(TetrisGame ${SOURCES})

target_link_libraries(TetrisGame ${SDL2_LIBRARIES} ${SDL2_gfx_LIBRARIES})

#for compiling the program g++ -o tetris_game src/main.cpp src/IO.cpp src/Game.cpp src/Pieces.cpp src/Board.cpp \
    # -I/opt/homebrew/Cellar/sdl2/2.30.6/include \
    # -I/opt/homebrew/Cellar/sdl2_gfx/1.0.4/include \
    # -L/opt/homebrew/Cellar/sdl2/2.30.6/lib \
    # -L/opt/homebrew/Cellar/sdl2_gfx/1.0.4/lib \
    # -lSDL2 -lSDL2_gfx 
