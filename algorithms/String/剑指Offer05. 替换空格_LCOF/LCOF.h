//
// Created by 朱玥 on 2022/8/4.
//

#pragma once

#include <string>

using namespace std;

class Solution01 {
public:
  string replaceSpace(string s) {
    string result = "";
    for (auto c : s) {
      if (c == ' ') {
        result.push_back('%');
        result.push_back('2');
        result.push_back('0');
      } else {
        result.push_back(c);
      }
    }
    return result;
  }
};

class Solution02 {
public:
  string replaceSpace(string s) {
    int count = 0; // 统计空格的个数
    int ori_size = s.size();
    for (auto c : s) {
      if (c == ' ') count++;
    }
    // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
    s.resize(s.size() + count * 2);
    int new_size = s.size();
    // 从后先前将空格替换为"%20"
    for (int i = new_size - 1, j = ori_size - 1; j < i; i--, j--) {
      if (s[j] != ' ') {
        s[i] = s[j];
      } else {
        s[i] = '0';
        s[i - 1] = '2';
        s[i - 2] = '%';
        i -= 2;
      }
    }
    return s;
  }
};
