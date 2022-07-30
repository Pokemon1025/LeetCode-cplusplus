//
// Created by 朱玥 on 2022/7/31.
//

#include "WordBreak.h"
#include <gtest/gtest.h>

class WordBreakTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(WordBreakTest, TestSolution) {
  Solution s;
  string a = "applepenapple";
  vector<string> b{"apple", "pen"};
  EXPECT_EQ(true, s.wordBreak(a, b));
}
