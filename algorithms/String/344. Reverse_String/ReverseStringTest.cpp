//
// Created by 朱玥 on 2022/8/4.
//

#include "ReverseString.h"
#include <gtest/gtest.h>

class ReverseStringTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(ReverseStringTest, TestSolution) {
  Solution s;
  vector<char> str {'h','e','l','l','o'};
  vector<char> str_reverse {'o', 'l', 'l', 'e', 'h'};
  s.reverseString(str);
  EXPECT_EQ(true, str_reverse == str);
}