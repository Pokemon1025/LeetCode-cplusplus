//
// Created by 朱玥 on 2022/6/12.
//

#pragma once

//时间复杂度：O(n)
//空间复杂度：O(1)
class Solution {
public:
  int tribonacci(int n)
  {
    if (n == 0) return 0;
    if (n < 3) return 1;
    int pprev = 0, prev = 1, cur = 1;
    for (int i = 3; i <= n; i++)
    {
      cur += pprev + prev;
      prev = cur - pprev - prev;
      pprev = cur - pprev - prev;
    }
    return cur;
  }
};

