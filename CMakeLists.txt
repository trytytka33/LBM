cmake_minimum_required(VERSION 3.11)
project(LBM)

set(CMAKE_CXX_STANDARD 17)

find_package(raylib QUIET)

if(NOT raylib_FOUND)
    include_directories(C:/msys64/ucrt64/include)
    link_directories(C:/msys64/ucrt64/lib)
    set(RAYLIB_LIBS raylib opengl32 gdi32 winmm)
else()
    set(RAYLIB_LIBS raylib)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(lbm 
    src/main.cpp
    src/Grid.cpp
    src/Button.cpp
    src/Renderer.cpp
    src/InputHandler.cpp
    src/Simulation.cpp
    src/Cell.cpp
)
target_link_libraries(lbm ${RAYLIB_LIBS})