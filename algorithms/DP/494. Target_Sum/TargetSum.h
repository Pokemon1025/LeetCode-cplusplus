//
// Created by 朱玥 on 2022/7/27.
//

#pragma once
#include <vector>

using namespace std;

// 01背包，一维数组
// 时间复杂度：O(n × m)，n为正数个数，m为背包容量
// 空间复杂度：O(m)，m为背包容量
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    //sp + sn = sum
    //sp - sn = target
    //-> 2sp = sum + target
    int sum = 0;
    for (int num : nums) sum += num;
    // 此时没有方案
    if (abs(target) > sum) return 0;
    int total = sum + target;
    if (total % 2 != 0) return 0;//计算的过程中不能向下取整
    int target_pos = total / 2;
    if (target_pos < 0) return 0;
    // 开始 dp
    vector<int> dp(target_pos + 1, 0);
    dp[0] = 1;
    for (int num : nums) {
      for (int j = target_pos; j >= num; j--) {
        dp[j] += dp[j - num];
      }
    }
    return dp[target_pos];
  }
};