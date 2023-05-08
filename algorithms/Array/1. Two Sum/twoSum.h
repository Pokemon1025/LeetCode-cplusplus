//
// Created by 朱玥 on 2022/6/12.
//

#pragma once

#include <vector>

using namespace std;
//时间复杂度：O(n*n)
//空间复杂度：O(1)
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    auto n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }
    return {};
  }
};

