//
// Created by 朱玥 on 2022/7/25.
//

#include "UniqueBinarySearchTrees.h"
#include <gtest/gtest.h>

class UniqueBinarySearchTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(UniqueBinarySearchTest, TestSolution01) {
  Solution01 s;
  EXPECT_EQ(5, s.numTrees(3));
}


