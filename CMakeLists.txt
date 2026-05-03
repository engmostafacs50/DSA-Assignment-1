cmake_minimum_required(VERSION 3.10)

project(DSA_Assignment_1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(problem2
    PartB_Search_Sorting/problem2_rotated_binary_search/main.cpp
    PartB_Search_Sorting/problem2_rotated_binary_search/RotatedBinarySearch.cpp
 )

target_include_directories(problem2 PRIVATE
    PartB_Search_Sorting/problem2_rotated_binary_search
)

add_executable(problem3
    PartB_Search_Sorting/problem3_bitonic_array/main.cpp
 
 )

target_include_directories(problem3 PRIVATE
    PartB_Search_Sorting/problem3_bitonic_array
)

add_executable(problem4
    PartC_Stack_Queue/problem4_round_robin/main.cpp
    PartC_Stack_Queue/problem4_round_robin/Scheduler.cpp
 )

target_include_directories(problem4 PRIVATE
    PartC_Stack_Queue/problem4_round_robin
)

add_executable(problem5 
    PartC_Stack_Queue/Problem5_Stack_MathmaticalExepression/main.cpp
)

target_include_directories(problem5 PRIVATE
    PartC_Stack_Queue/Problem5_Stack_MathmaticalExepression
)