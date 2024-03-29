cmake_minimum_required(VERSION 3.12.0)
project(pac-gl VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(OpenAL REQUIRED)

add_executable(pac-gl 
    src/main.cpp
    src/cube.cpp
    src/game.cpp
    src/ghost.cpp
    src/pacman.cpp
    src/sound.cpp
    )

include_directories(include ${OPENAL_INCLUDE_DIR})

target_link_libraries(pac-gl GLUT::GLUT OpenGL::GLU OpenGL::GL alut ${OPENAL_LIBRARY})
