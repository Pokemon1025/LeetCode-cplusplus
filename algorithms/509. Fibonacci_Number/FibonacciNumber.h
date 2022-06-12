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
