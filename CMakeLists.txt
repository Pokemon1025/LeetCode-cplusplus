cmake_minimum_required(VERSION 3.22)
project(LeetCode_cplusplus)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCode_cplusplus
        "algorithms/509. Fibonacci_Number/FibonacciNumber.h"
        "algorithms/1137. N-th_Tribonacci_Number/nthTribonacciNumber.h"
        "algorithms/46. Permutations/permutations.h"
        "algorithms/121. Best_Time_to_Buy_and_Sell_Stock/bestTimeToBuyAndSellStock.h"
        "algorithms/222. Count_Complete_Tree_Nodes/countCompleteTreeNodes.h"
        "algorithms/704. Binary_Search/binarySearch.h"
        "algorithms/150. Evaluate_Reverse_Polish_Notation/evaluateReversePolishNotation.h"
        algorithms/main.cpp)
