//
// Created by 朱玥 on 2022/8/4.
//

// 回文子串是要连续的，回文子序列可不是连续的

#include <vector>
#include <string>

using namespace std;

// dp[i][j] 表示字符串 ss 的下标范围 [i, j][i,j] 内的最长回文子序列的长度
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      for (int j = i + 1; j < s.size(); j++) {
        if (s[i] != s[j]) dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        else dp[i][j] = dp[i + 1][j - 1] + 2;
      }
    }
    return dp[0][s.size() - 1];
  }
};