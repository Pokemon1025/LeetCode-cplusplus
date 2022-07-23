//
// Created by 朱玥 on 2022/7/23.
//

#include "ClimbingStairs.h"
#include <gtest/gtest.h>

class ClimbingStairsTest : public testing::Test {
protected:
  virtual void TearDown() {}
  virtual void SetUp() {}
};

TEST(Solution01, TestSolution01) {
  Solution01 s;
  EXPECT_EQ(13, s.climbStairs(6));
}
