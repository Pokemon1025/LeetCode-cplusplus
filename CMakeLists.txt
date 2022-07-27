cmake_minimum_required(VERSION 3.22)
project(LeetCode_cplusplus)

set(CMAKE_CXX_STANDARD 14)

# The folder with Google Test sources
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/third-party/googletest)
include_directories(googletest/include googletest)

include_directories(
        ${CMAKE_CURRENT_LIST_DIR}/algorithms
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/DP/70.\ Climbing_Stairs
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/DP/509.\ Fibonacci_Number
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/List
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/46.\ Permutations
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/121.\ Best_Time_to_Buy_and_Sell_Stock
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/150.\ Evaluate_Reverse_Polish_Notation
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/206.\ Reverse_Linked_List
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/222.\ Count_Complete_Tree_Nodes
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/704.\ Binary_Search
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/1137.\ N-th_Tribonacci_Number
)


# Source files with tests
add_executable(LeetCode_cplusplus
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/DP/70.\ Climbing_Stairs/ClimbingStairsTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/DP/62.\ Unique_Paths/UniquePathsTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/DP/96.\ Unique_Binary_Search_Trees/UniqueBinarySearchTreesTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/DP/416.\ Partition_Equal_Subset_Sum/PartitionEqualSubsetSumTest.cpp
        ${CMAKE_CURRENT_LIST_DIR}/algorithms/DP/494.\ Target_Sum/TargetSumTest.cpp
        algorithms/main.cpp)

target_link_libraries(LeetCode_cplusplus gtest gtest_main)
