//
// Created by 朱玥 on 2022/7/29.
//

#pragma once
#include <vector>

using namespace std;

// 完全背包
// 平方数就是物品（可以无限件使用），凑个正整数n就是背包，问凑满这个背包最少有多少物品
// 递推公式：dp[j] = min(dp[j - i * i] + 1, dp[j]);
class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i <= n; i++) {  // 遍历背包
      for (int j = 1; j * j <= i; j++) { // 遍历物品, i = 0 时不进入循环
        dp[i] = min(dp[i - j * j] + 1, dp[i]);
      }
    }
    return dp[n];
  }
};
