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

TEST(PalindromicSubstringsTest, TestSolution01) {
  Solution01 s;
  EXPECT_EQ(6, s.countSubstrings("aaa"));
}

TEST(PalindromicSubstringsTest, TestSolution02) {
  Solution02 s;
  EXPECT_EQ(6, s.countSubstrings("aaa"));
}

TEST(PalindromicSubstringsTest, TestSolution03) {
  Solution03 s;
  EXPECT_EQ(6, s.countSubstrings("aaa"));
}