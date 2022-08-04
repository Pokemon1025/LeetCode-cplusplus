//
// Created by 朱玥 on 2022/8/4.
//

#pragma once
#include <vector>

using namespace std;
// 双指针
// left+ right-
class Solution {
public:
  void reverseString(vector<char> &s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      swap(s[i], s[j]);
    }
  }
};