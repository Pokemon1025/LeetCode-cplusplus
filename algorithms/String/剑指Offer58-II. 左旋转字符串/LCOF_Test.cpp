//
// Created by 朱玥 on 2022/8/4.
//

#include "LCOF_.h"
#include <gtest/gtest.h>

class LCOFTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(LCOF_Test, TestSolution01) {
  Solution s;
  string str{"lrloseumgh"};
  EXPECT_EQ("umghlrlose", s.reverseLeftWords(str, 6));
}