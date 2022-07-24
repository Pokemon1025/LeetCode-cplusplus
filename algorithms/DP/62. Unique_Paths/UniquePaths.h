//
// Created by 朱玥 on 2022/7/24.
//

#pragma once

#include <vector>

using namespace std;

/* m = 3, n = 5
 * | 1    | 1    | 1    | 1    | 1    |
 * | 1    | 2    | 3    | 4    | 5    |
 * | 1    | 3    | 6    | 10   | 15   |
 * */

// 解法一：二维数组，层级遍历
// 时间复杂度：O(m × n)
// 空间复杂度：O(m × n)
class Solution01 {
public:
  int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    // dp[i][0]一定都是1，因为从(0, 0)的位置到(i, 0)的路径只有一条，那么dp[0][j]也同理。
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];//dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径。
      }
    }
    return dp[m - 1][n - 1];
  }
};

// 解法二：优化空间，使用一维数组
// 时间复杂度：O(m × n)
// 空间复杂度：O(n)
class Solution02 {
public:
  int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    // for (int i = 0; i < n; i++) dp[i] = 1;
    for (int j = 1; j < m; j++) {
      for (int i = 1; i < n; i++) {
        dp[i] += dp[i - 1];
      }
    }
    return dp[n - 1];
  }
};

// 解法三：数论方法
// m + n - 2个不同的数，随便取m - 1个数，有几种取法
// 算式：
//   m - 1
// C m + n - 2
// 时间复杂度：O(m)
// 空间复杂度：O(1)
class Solution03 {
public:
  int uniquePaths(int m, int n) {
    long long numerator = 1; // 分子
    int denominator = m - 1; // 分母
    int count = m - 1;
    int t = m + n - 2;
    while (count--) {
      numerator *= (t--);
      while (denominator != 0 && numerator % denominator == 0) {
        numerator /= denominator;
        denominator--;
      }
    }
    return static_cast<int>(numerator);
  }
};

// dfs超时，时间复杂度为O(2^(m + n - 1) - 1)，为指数级别，这里不做赘述