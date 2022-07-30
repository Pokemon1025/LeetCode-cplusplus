//
// Created by 朱玥 on 2022/7/31.
//

#pragma once

#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

// 时间复杂度：O(n^3)
// 空间复杂度：O(n)
// 递推公式:  if([j, i] 这个区间的子串出现在字典里 && dp[j]是true) 那么 dp[i] = true
class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true; // 初始化类型注意是bool，且为了递推进行，赋值为true！
    for (int i = 1; i <= s.size(); i++) { // 遍历背包, 注意 <=
      for (int j = 0; j < i; j++) {       // 遍历物品
        string word = s.substr(j, i - j); // substr(起始位置，截取的个数)
        if (wordSet.find(word) != wordSet.end() && dp[j]) {
          dp[i] = true; // 字符串长度为 i 可以拆分为一个或多个在字典中出现的单词
          break;
        }
      }
    }
    return dp[s.size()];
  }
};