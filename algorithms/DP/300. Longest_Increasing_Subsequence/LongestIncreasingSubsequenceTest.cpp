//
// Created by 朱玥 on 2022/7/31.
//
#include "LongestIncreasingSubsequence.h"
#include <gtest/gtest.h>

class LongestIncreasingSubsequenceTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(LongestIncreasingSubsequenceTest, TestSolution) {
  Solution s;
  vector<int> nums{10,9,2,5,3,7,101,18};
  EXPECT_EQ(4, s.lengthOfLIS(nums));
}
