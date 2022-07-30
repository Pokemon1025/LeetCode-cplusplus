//
// Created by 朱玥 on 2022/7/29.
//

#include "PerfectSquares.h"
#include <gtest/gtest.h>

class PerfectSquaresTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(PerfectSquaresTest, TestSolution) {
  Solution s;
  EXPECT_EQ(3, s.numSquares(12));
}
