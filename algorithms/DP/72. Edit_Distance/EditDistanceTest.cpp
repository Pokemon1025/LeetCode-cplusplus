//
// Created by 朱玥 on 2022/8/2.
//

#include "EditDistance.h"
#include <gtest/gtest.h>

class EditDistanceTestTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(EditDistanceTestTest, TestSolution01) {
  Solution s;
  EXPECT_EQ(5, s.minDistance("intention", "execution"));
}
