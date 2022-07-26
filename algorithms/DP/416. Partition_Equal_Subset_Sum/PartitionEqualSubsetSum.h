//
// Created by 朱玥 on 2022/7/26.
//

#pragma once

#include <vector>
#include <bitset>
#include <numeric>

using namespace std;

// 解法一，bitset优化dp，转换为二进制理解
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution01 {
public:
  bool canPartition(vector<int> &nums) {
    if (nums.size() < 2)
      return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1)//判断是否是奇数
      return false;

    // 题目中说：每个数组中的元素不会超过 100，数组的大小不会超过 200
    // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
    const int NUM_MAX = 10001;
    bitset<NUM_MAX> bits(1);//bitset的长度是
    for (const auto n : nums)
      bits |= bits << n;//状态转移

    return bits[sum >> 1];//是否找到解
  }
};

// 时间复杂度：O(n^2)
// 空间复杂度：O(n)，虽然dp数组大小为一个常数，但是大常数
class Solution02 {
public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    vector<int> dp(10001, 0);
    for (int num : nums) sum += num;
    if (sum % 2 == 1) return false;
    int target = sum / 2;
    // 开始 01背包
    for (int num : nums) {
      for (int j = target; j >= num; j--) { // 每一个元素一定是不可重复放入，所以从大到小遍历
        dp[j] = max(dp[j], dp[j - num] + num);
      }
    }
    // 集合中的元素正好可以凑成总和target
    if (dp[target] == target) return true;
    return false;
  }
};