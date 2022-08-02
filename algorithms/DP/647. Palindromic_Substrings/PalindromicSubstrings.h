//
// Created by 朱玥 on 2022/8/2.
//

#pragma once

#include <vector>
#include <string>

using namespace std;

// 从下到上，从左到右遍历，保证dp[i + 1][j - 1]都是经过计算的
// j >= i，填充dp[i][j]的时候只填充右上半部分
// | 1    | 1    | 1    |
// | 0    | 1    | 1    |
// | 0    | 0    | 1    |
class Solution {
public:
  int countSubstrings(string s) {
    // dp[i][j]初始化的时候，就初始为false，所以循环中不用考虑不相等的时候
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i; j < s.size(); j++) {
        if (s[i] != s[j])
          continue;
        if (j - i <= 1) {// "a"|"aa"
          res++;
          dp[i][j] = true;
        } else if (dp[i + 1][j - 1]) {//"cabac" i为第一个a的索引 j为倒数第一个a的索引
          res++;
          dp[i][j] = true;
        }
      }
    }
    return res;
  }
};
