//
// Created by 朱玥 on 2022/7/28.
//

#include "CoinChange.h"
#include <gtest/gtest.h>

class CoinChangeTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(CoinChangeTest, TestSolution01) {
  Solution01 s;
  vector<int> coins{1, 2, 5};
  EXPECT_EQ(3, s.coinChange(coins, 11));
}

TEST(CoinChangeTest, TestSolution02) {
  Solution02 s;
  vector<int> coins{1, 2, 5};
  EXPECT_EQ(3, s.coinChange(coins, 11));
}