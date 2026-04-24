cmake_minimum_required(VERSION 3.10)

project(DSA_Assignment_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(problem2
    problem2_rotated_binary_search/problem2_rotated_binary_search/main.cpp
    problem2_rotated_binary_search/problem2_rotated_binary_search/RotatedBinarySearch.cpp
)

target_include_directories(problem2 PRIVATE
    problem2_rotated_binary_search/problem2_rotated_binary_search
)

add_executable(problem4
    PartC_Stack_Queue/problem4_round_robin/main.cpp
    PartC_Stack_Queue/problem4_round_robin/Scheduler.cpp
)

target_include_directories(problem4 PRIVATE
    PartC_Stack_Queue/problem4_round_robin
)