//
// Created by 朱玥 on 2022/8/2.
//

#include "PalindromicSubstrings.h"
#include <gtest/gtest.h>

class PalindromicSubstringsTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(PalindromicSubstringsTest, TestSolution) {
  Solution s;
  EXPECT_EQ(6, s.countSubstrings("aaa"));
}