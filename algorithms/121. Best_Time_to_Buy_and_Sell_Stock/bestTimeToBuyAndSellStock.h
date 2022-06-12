//
// Created by 朱玥 on 2022/6/13.
//
#pragma once

#include <vector>
using namespace std;
class Solution {
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
