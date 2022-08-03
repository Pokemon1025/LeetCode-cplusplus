//
// Created by 朱玥 on 2022/8/4.
//

#include "LongestPalindromicSubsequence.h"
#include <gtest/gtest.h>

class LongestPalindromicSubsequenceTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(LongestPalindromicSubsequenceTest, TestSolution) {
  Solution s;
  EXPECT_EQ(4, s.longestPalindromeSubseq("bbbab"));
}
