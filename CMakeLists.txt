cmake_minimum_required(VERSION 3.20)
project(2DSnakeGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(2DSnakeGame main.cpp Game.cpp Game.h Snake.cpp Snake.h Bait.cpp Bait.h Snake_Part.cpp Snake_Part.h Game_Block.cpp Game_Block.h)

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR C:/SFML/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(2DSnakeGame sfml-system sfml-graphics sfml-window sfml-audio sfml-network)