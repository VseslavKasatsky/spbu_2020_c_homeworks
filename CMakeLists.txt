cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c)

add_library(library ${SOURCE_LIB})
add_library(stackPostfix library/commonUtils/stackPostfix.c)
add_library(list library/commonUtils/list.c)
add_library(binarySearchAndAvlTree library/commonUtils/binarySearchAndAvlTree.c)
add_library(hashTable library/commonUtils/hashTable.c)

add_executable(1.task_1 Homework_1/task_1.c)
add_executable(1.task_2 Homework_1/task_2.c)
add_executable(1.task_3 Homework_1/task_3.c)
add_executable(1.task_4 Homework_1/task_4.c)
add_executable(1.task_5 Homework_1/task_5.c)
add_executable(2.task_1 Homework_2/task_1.c)
add_executable(2.task_2 Homework_2/task_2.c)
add_executable(2.task_3 Homework_2/2.task_3.c)
add_executable(2.task_4 Homework_2/2.task_4.c)
add_executable(2.task_5i Homework_2/task_5.iterative.c)
add_executable(2.task_5r Homework_2/task_5.recursive.c)

add_executable(3.task_1 Homework_3/task_1.c)
target_link_libraries(3.task_1 list)
add_executable(3.task_2 Homework_3/task_2.c)
target_link_libraries(3.task_2 list)

add_executable(4.task_1 Homework_4/task_1.c)
target_link_libraries(4.task_1 stackPostfix)
add_executable(4.task_2 Homework_4/task_2.c)
add_executable(4.task_3 Homework_4/task_3.c)

add_executable(5.task_1 Homework_5/task_1.c)
target_link_libraries(5.task_1 binarySearchAndAvlTree)

add_executable(5.task_2 Homework_5/task_2.c)
target_link_libraries(5.task_2 binarySearchAndAvlTree)

add_executable(6.task_1 Homework_6/task_1.c)
target_link_libraries(6.task_1 hashTable)

add_executable(Test_1 Test/task_1.c)
add_executable(Test_2 Test/task_2.c library/commonUtils/test1_2.c)
