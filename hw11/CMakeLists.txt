cmake_minimum_required(VERSION 3.20)
project(hw11 C)

set(CMAKE_C_STANDARD 99)

add_executable(hw11
        hw11.c
        maze.c
        maze.h
        mazehelper.c
        mazehelper.h
        path.c
        path.h
        solver.c
        solver.h
        list.c
        list.h)
