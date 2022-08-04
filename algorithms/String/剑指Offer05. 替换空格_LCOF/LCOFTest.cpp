//
// Created by 朱玥 on 2022/8/4.
//

#include "LCOF.h"
#include <gtest/gtest.h>

class LCOFTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(LCOFTest, TestSolution01) {
  Solution01 s;
  string str {"We are happy."};
  EXPECT_EQ("We%20are%20happy.", s.replaceSpace(str));
}