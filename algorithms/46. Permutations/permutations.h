//
// Created by 朱玥 on 2022/6/13.
//

/**********************************************************************************
*
* Given a collection of numbers, return all possible permutations.
*
* For example,
* [1,2,3] have the following permutations:
* [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*
*
**********************************************************************************/
#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<int> &nums)
  {
    if (nums.empty())
    {
      ret.emplace_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
      path.emplace_back(nums[i]);
      int temp = nums[i];
      nums.erase(nums.begin() + i);
      dfs(nums);
      nums.emplace(nums.begin() + i, temp);
      path.pop_back();
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    dfs(nums);
    return ret;
  }

private:
  vector<vector<int>> ret;
  vector<int> path;
};
