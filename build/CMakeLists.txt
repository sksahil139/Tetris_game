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
