//
// Created by 朱玥 on 2022/7/31.
//

#pragma once

#include <vector>

using namespace std;

// 子序列问题
// 递推公式：位置i的最长升序子序列等于 j (从 0 到 i-1 各个位置的最长升序子序列) +1 的最大值
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() <= 1) return nums.size();
    vector<int> dp(nums.size(), 1); // 初始化一维数组，默认值为1
    int result = 0;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) //外层基准 > 内层对照
          dp[i] = max(dp[i], dp[j] + 1);
      }
      result = max(dp[i], result); // 取长的子序列
    }
    return result;
  }
};