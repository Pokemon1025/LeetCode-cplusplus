//
// Created by 朱玥 on 2022/7/31.
//

#pragma once

#include <vector>

using namespace std;

// dp[i]只有两个方向可以推出来：
// dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
// nums[i]，即：从头开始计算当前连续子序列和
// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size());
    dp[0] = nums[0];//dp[i]：包括下标i之前的最大连续子序列和为dp[i]
    int result = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 状态转移公式
      result = max(dp[i], result);               // result 保存dp[i]的最大值
    }
    return result;
  }
};
