//
// Created by 朱玥 on 2022/6/14.
//
//二分法核心：坚持根据查找区间的定义来做边界处理
#pragma once
#include <vector>

using namespace std;
class Solution01 {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;//定义target在左闭右闭区间，[left, right];
    while (left <= right) { //当left = right时区间仍有效
      int mid = left + (right - left) / 2;//防止溢出
      int num = nums[mid];
      if (num < target)
        left = mid + 1;//target 在右区间，[middle + 1, right]
      else if (num > target)
        right = mid - 1;//target 在左区间，[left, middle - 1]
      else
        return mid;
    }
    return -1;
  }
};

class Solution02 {
public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size());// 定义target在左闭右开的区间里，即：[left, right)
    while (left < right) {// 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
      int mid = left + ((right - left) >> 1);
      int num = nums[mid];
      if (num > target)
        right = mid;// target 在左区间，在[left, middle)中
      else if (num < target)
        left = mid + 1;// target 在右区间，在[middle + 1, right)中
      else
        return mid;
    }
    return -1;
  }
};
