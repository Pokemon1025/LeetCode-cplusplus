//
// Created by 朱玥 on 2022/7/31.
//

#pragma once

#include <vector>

using namespace std;

class Solution {
public:
  int maxSubVec(vector<int>& nums) {
    if (nums.size() <= 1)
      return nums.size();
    vector<int> dp(nums.size(), 1);
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      if (dp[i] > result)
        result = dp[i];
    }
    return result;
  }
};
