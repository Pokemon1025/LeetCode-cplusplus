//
// Created by 朱玥 on 2022/8/7.
//

#pragma once

#include <string>

using namespace std;

// 要求：不要使用辅助空间，空间复杂度要求为O(1)
// 思路：1) 移除多余空格 2) 将整个字符串反转 3) 将每个单词反转
class Solution {
public:
  void removeSpace(string &s) {
    int slow = 0;
    for (int fast = 0; fast < s.size(); fast++) {
      if (s[fast] != ' ') { //遇到非空格就处理，即删除所有空格
        if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格
        while (fast < s.size() && s[fast] != ' ') { //补上该单词，遇到空格说明单词结束
          s[slow++] = s[fast++];
        }
      }
    }
    s.resize(slow); //slow的大小即为去除多余空格后的大小。
  }
  string reverseWords(string s) {
    removeSpace(s);
    reverse(s.begin(), s.end());
    int left = 0;//移除空格后保证第一个单词的开始下标一定是0
    for (int right = 0; right <= s.size(); right++) {
      //到达空格或者串尾，说明一个单词结束。进行翻转
      if (s[right] == ' ' || right == s.size()) {
        reverse(s.begin() + left, s.begin() + right);//左闭右闭 []的翻转
        right++;
        left = right;//更新下一个单词的开始下标left
      }
    }
    return s;
  }
};
