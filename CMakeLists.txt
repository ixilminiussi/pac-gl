cmake_minimum_required(VERSION 3.0.0)
project(pac-gl VERSION 0.1.0 LANGUAGES C CXX)

add_executable(pac-gl src/main.cpp)

target_link_libraries(pac-gl SDL2main SDL2 GL)
