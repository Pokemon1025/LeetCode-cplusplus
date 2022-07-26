//
// Created by 朱玥 on 2022/7/27.
//

#include "PartitionEqualSubsetSum.h"
#include <gtest/gtest.h>

class PartitionEqualSubsetSumTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(PartitionEqualSubsetSumTest, TestSolution01) {
  Solution01 s;
  vector<int> nums{1, 5, 11, 5};
  EXPECT_EQ(true, s.canPartition(nums));
}

TEST(PartitionEqualSubsetSumTest, TestSolution02) {
  Solution02 s;
  vector<int> nums{1, 5, 11, 5};
  EXPECT_EQ(true, s.canPartition(nums));
}
