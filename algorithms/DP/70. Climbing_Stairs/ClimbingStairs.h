//
// Created by 朱玥 on 2022/7/23.
//

#pragma once
#include <vector>
#include <gtest/gtest.h>
using namespace std;

// dp标准版本
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution01 {
public:
  int climbStairs(int n) {
    if (n <= 1)
      return n;
    vector<int> dp(n + 1);
    dp[1] = 1, dp[2] = 2; // dp初始化：dp[0] = 1,
                          // i从2开始遍历也能过，但本题不应该讨论dp[0]的初始化
    for (int i = 3; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  }
};

// 版本二，优化空间复杂度
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution02 {
public:
  int climbStairs(int n) {
    if (n <= 1) return n;
    int dp[3];
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      int sum = dp[2] + dp[1];
      dp[1] = dp[2];
      dp[2] = sum;
    }
    return dp[2];
  }
};

// 版本三，不引入变量
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution03 {
public:
  int climbStairs(int n) {
    if (n <= 1) return n;
    int dp[3];
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[2] += dp[1];
      dp[1] = dp[2] - dp[1];
    }
    return dp[2];
  }
};