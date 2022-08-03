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
// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution01 {
public:
  int countSubstrings(string s) {
    // dp[i][j]初始化的时候，就初始为false，所以循环中不用考虑不相等的时候
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i; j < s.size(); j++) {
        if (s[i] != s[j]) // "ab" 这里注意过滤规则是判断俩字符是否相等
          continue;
        if (j - i <= 1) { // "a"|"aa"
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


// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution02 {
public:
  int countSubstrings(string s) {
    // dp[i][j]初始化的时候，就初始为false，所以循环中不用考虑不相等的时候
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i; j < s.size(); j++) {
        if (s[i] != s[j]) // "ab" 这里注意过滤规则是判断俩字符是否相等
          continue;
        if ((j - i <= 1) || (dp[i + 1][j - 1])) {
          res++;
          dp[i][j] = true;
        }
      }
    }
    return res;
  }
};

// 双指针
// 确定回文串，找中心然后向两边扩散是不是对称，中心可能包含一个元素或两个元素
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution03 {
public:
  int countSubstrings(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      result += extend(s, i, i, s.size());     // 以i为中心
      result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
    }
    return result;
  }
  int extend(const string &s, int i, int j, int n) {
    int res = 0;
    while (i >= 0 && j < n && s[i] == s[j]) {
      i--;
      j++;
      res++;
    }
    return res;
  }
};
