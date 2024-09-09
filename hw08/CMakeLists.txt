cmake_minimum_required(VERSION 3.20)
project(hw08 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(hw08
        main.c
        shuffle.c
        shuffle.h
        Makefile)
