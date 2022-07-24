//
// Created by 朱玥 on 2022/7/24.
//
#include "UniquePaths.h"
#include <gtest/gtest.h>

class UniquePathsTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(UniquePathsTest, TestSolution01) {
  Solution01 s;
  EXPECT_EQ(15, s.uniquePaths(3, 5));
}

TEST(UniquePathsTest, TestSolution02) {
  Solution02 s;
  EXPECT_EQ(15, s.uniquePaths(3, 5));
}

TEST(UniquePathsTest, TestSolution03) {
  Solution03 s;
  EXPECT_EQ(15, s.uniquePaths(3, 5));
}

