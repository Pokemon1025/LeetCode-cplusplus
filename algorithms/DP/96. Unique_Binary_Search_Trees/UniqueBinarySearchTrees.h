//
// Created by 朱玥 on 2022/7/25.
//

#pragma once

#include <vector>
using namespace std;
// return the number of structurally unique BST's (binary search trees)
// 关键：找出重叠子问题

/*
 * 例：n = 3
 * 元素1为头结点搜索树的数量 = 右子树有2个元素的搜索树数量 * 左子树有0个元素的搜索树数量
 * 元素2为头结点搜索树的数量 = 右子树有1个元素的搜索树数量 * 左子树有1个元素的搜索树数量
 * 元素3为头结点搜索树的数量 = 右子树有0个元素的搜索树数量 * 左子树有2个元素的搜索树数量
 * 有2个元素的搜索树数量 = dp[2]
 * 有1个元素的搜索树数量 = dp[1]
 * 有0个元素的搜索树数量 = dp[0]
 * dp[3] = dp[2] * dp[0] + dp[1] * dp[1] + dp[0] * dp[2]
 * */

// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution01 {
public:
  int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1; // dp初始化，避免乘法结果异常
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        dp[i] += dp[j - 1] * dp[i - j];// dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]
      }
    }
    return dp[n];
  }
};
