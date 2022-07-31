//
// Created by 朱玥 on 2022/6/13.
//
#pragma once

#include <vector>
using namespace std;

class Solution01 {
public:
  int maxProfit(vector<int> &prices)
  {
    const int n = static_cast<int>(prices.size());
    if (n < 1)
      return 0;
    int buy = INT_MAX;//最低买入点
    int profit = 0;//最大收益
    for (const auto &p: prices)
    {
      buy = min(buy, p);
      profit = max(profit, p - buy);
    }
    return profit;
  }
};

// 假如计划在第 i 天卖出股票，那么最大利润的差值一定是在[0, i-1] 之间选最低点买入；
// 所以遍历数组，依次求每个卖出时机的的最大差值，再从中取最大值。

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution02 {
public:
  int maxProfit(vector<int> &prices) {
    int len = prices.size();
    if (len == 0) return 0;
    // 开辟了一个 n * 2 大小的二维数组
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
      dp[i][0] = max(dp[i - 1][0], -prices[i]);
      dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
    }
    return dp[len - 1][1];
  }
};

// 滚动数组
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution03 {
public:
  int maxProfit(vector<int>& prices) {
    int len = prices.size();
    vector<vector<int>> dp(2, vector<int>(2)); // 注意这里只开辟了一个2 * 2 大小的二维数组
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
      dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i]);
      dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
    }
    return dp[(len - 1) % 2][1];
  }
};