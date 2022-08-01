//
// Created by 朱玥 on 2022/8/1.
//

#include <vector>
#include "string"

using namespace std;

// dp[i][j] 表示以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2
// 最近编辑距离为dp[i][j]。
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) dp[i][0] = i;
    for (int j = 1; j <= n; ++j) dp[0][j] = j;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];//统一以下标i-1为结尾的字符串，易理解
        else dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
      }
    }
    return dp[m][n];
  }
};