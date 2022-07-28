//
// Created by 朱玥 on 2022/7/28.
//

#pragma once

#include <vector>

using namespace std;

// 完全背包问题：每个硬币可以选择多次
// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。

//版本一
class Solution01 {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (auto i : coins) {           // 正序遍历物品
      for (int j = i; j <= amount; j++) { // 遍历背包
        if (dp[j - i] == INT_MAX)// 只有dp[j-coins[i]]不是初始最大值时，该位才有选择的必要
          continue;
        dp[j] = min(dp[j], dp[j - i] + 1);// 选择硬币数目最小的情况
      }
    }
    if (dp[amount] == INT_MAX) return -1;// 没找到能装满背包的, 就返回
    return dp[amount];
  }
};

//版本二
class Solution02 {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {           // 遍历物品
      for (auto j: coins) { // 遍历背包
        if (dp[i - j] == INT_MAX || i - j < 0)
          continue;
        dp[i] = min(dp[i], dp[i - j] + 1);
      }
    }
    if (dp[amount] == INT_MAX) return -1;
    return dp[amount];
  }
};