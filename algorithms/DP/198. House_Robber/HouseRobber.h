//
// Created by 朱玥 on 2022/7/31.
//

#pragma once

#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
public:
  int rob(vector<int> &nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[nums.size() - 1];
  }
};
