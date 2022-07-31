//
// Created by 朱玥 on 2022/8/1.
//

#include "MaximumSubarray.h"
#include <gtest/gtest.h>

class MaximumSubarrayTestTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(MaximumSubarrayTestTest, TestSolution01) {
  Solution s;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  EXPECT_EQ(6, s.maxSubArray(nums));
}