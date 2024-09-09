cmake_minimum_required(VERSION 3.20)
project(hw07 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(hw07
        main.c
        shuffle.c
        shuffle.h
        makefile)
