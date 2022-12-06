cmake_minimum_required(VERSION 3.23)
project(xoGame C)

set(CMAKE_C_STANDARD 99)

add_executable(xoGame main.c)
target_link_libraries(xoGame -lglut -lGLU -lGL -lm -lX11)
