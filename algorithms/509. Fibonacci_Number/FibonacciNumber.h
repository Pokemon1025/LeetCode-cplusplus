//
// Created by 朱玥 on 2022/6/12.
//
#pragma once
//1.动态规划 + 降维 - 状态数组空间压缩
//时间复杂度:O(n) 空间复杂度:O(1)
class Solution01 {
public:
  int fib(int n) {
    if (n < 2)  return n;
    int prev = 0, cur = 1;

    for (int i = 2; i <= n; ++i) {
      cur += prev;
      prev = cur - prev;
    }
    return cur;
  }
};

//2.状态转移方程
#include <cmath>
using namespace std;
class Solution02 {
public:
  int fib(int n)
  {
    if (n < 2) return n;
    double sqrt5 = sqrt(5);
    double fibN = (pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n)) / sqrt5;
    return static_cast<int>(round(fibN));
  }
};

// 3.dp
// 时间复杂度：O(n)
// 空间复杂度：O(n)
#include <vector>
class Solution03 {
public:
  int fib(int N) {
    if (N <= 1) return N;
    vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
  }
};

// 4.dp - 空间优化
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution04 {
public:
  int fib(int N) {
    if (N <= 1)
      return N;
    // 1)确定dp数组（dp table）以及下标的含义:第i个数的斐波那契数值是dp[i]
    int dp[2];
    // 3)dp数组如何初始化
    dp[0] = 0;
    dp[1] = 1;
    // 4)确定遍历顺序
    for (int i = 2; i <= N; i++) {
      // 2)确定递推公式:状态转移方程 dp[i] = dp[i - 1] + dp[i - 2];
      int sum = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = sum;
      // dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[1];
  }
};

// 5.递归
class Solution05 {
public:
  int fib(int N) {
    if (N < 2) return N;
    return fib(N - 1) + fib(N - 2);
  }
};
