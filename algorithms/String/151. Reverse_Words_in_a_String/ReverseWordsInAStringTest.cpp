//
// Created by 朱玥 on 2022/8/8.
//

#include "ReverseWordsinAString.h"
#include <gtest/gtest.h>

class ReverseWordsinAStringTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(ReverseWordsinAStringTest, TestSolution) {
  Solution s;
  string a = "a good   example";
  EXPECT_EQ("example good a", s.reverseWords(a));
}