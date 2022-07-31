//
// Created by 朱玥 on 2022/7/31.
//

#include "HouseRobber.h"
#include <gtest/gtest.h>

class HouseRobberTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(HouseRobberTest, TestSolution) {
  Solution s;
  vector<int> nums = {2, 7, 9, 3, 1};
  EXPECT_EQ(3, s.rob(nums));
}
