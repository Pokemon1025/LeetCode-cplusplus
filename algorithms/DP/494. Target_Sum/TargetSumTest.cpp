//
// Created by 朱玥 on 2022/7/28.
//

#include "TargetSum.h"
#include <gtest/gtest.h>

class TargetSumTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(TargetSumTest, TestSolution01) {
  Solution s;
  vector<int> nums{1, 1, 1, 1, 1};
  EXPECT_EQ(5, s.findTargetSumWays(nums, 3));
}
