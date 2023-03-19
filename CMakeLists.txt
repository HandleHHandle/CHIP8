cmake_minimum_required(VERSION 3.21)
project(CHIP8)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE sources
  src/*.c
  src/*.h
)

include_directories(${PROJECT_SOURCE_DIR}/src/)

add_executable(${PROJECT_NAME} ${sources})

find_package(SDL2 REQUIRED)

include_directories(${PROJECT_NAME} ${SDL2_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
