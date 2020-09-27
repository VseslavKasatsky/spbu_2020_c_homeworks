cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c
        library/commonUtils/list.c)
add_library(library ${SOURCE_LIB})

add_executable(1.task_1 Homework_1/task_1.c)
add_executable(1.task_2 Homework_1/task_2.c)
add_executable(1.task_3 Homework_1/task_3.c)
add_executable(1.task_4 Homework_1/task_4.c)
add_executable(1.task_5 Homework_1/task_5.c)
add_executable(2.task_4 Homework_2/2.task_4.c)
add_executable(2.task_3 Homework_2/2.task_3.c)
add_executable(2.task_5i Homework_2/task_5.iterative.c)
add_executable(2.task_5r Homework_2/task_5.recursive.c)
add_executable(3.task_1 Homework_3/task_1.c library/commonUtils/list.c)
