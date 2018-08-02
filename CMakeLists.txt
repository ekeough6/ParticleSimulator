cmake_minimum_required(VERSION 3.10)
project(ParticleSImulator)

set(CMAKE_CXX_STANDARD 11)
find_package(SDL2 REQUIRED)
add_executable(ParticleSImulator main.cpp Screen.cpp Screen.h Particle.cpp Particle.h Swarm.cpp Swarm.h)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES})