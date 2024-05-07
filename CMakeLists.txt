cmake_minimum_required(VERSION 3.26)
project(untitled21 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled21 main.c)

add_library(str tasks/string_.c
        tasks/string_.h
        first_task.c
        second_task.c
        third_task.c
        fourth_task.c
        fifth_task.c
        sixth_task.c
        seventh.c
        eighth_task.c
        ninth_task.c
        tenth_task.c
        eleventh_task.c
        twelfth_task.c
        thirteenth_task.c
        thirteenth_task.c
        fourteenth_task.c
        fifteenth_task.c
        eleventh16_task.c
        seventeenth_task.c
)

target_link_libraries(untitled21 str)