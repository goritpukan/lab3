cmake_minimum_required(VERSION 3.29)
project(lab_3 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab_3 main.c
        src/validation.c
        include/validation.h
        src/calculations.c
        include/calculations.h
        main.c)

target_link_libraries(lab_3 m)