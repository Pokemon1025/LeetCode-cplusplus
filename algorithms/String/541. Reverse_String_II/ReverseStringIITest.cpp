//
// Created by 朱玥 on 2022/8/4.
//

#include "ReverseStringII.h"
#include <gtest/gtest.h>

class ReverseStringIITest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(ReverseStringIITest, TestSolution) {
  Solution s;
  string str {"abcdefg"};
  EXPECT_EQ("bacdfeg", s.reverseStr(str, 2));
}