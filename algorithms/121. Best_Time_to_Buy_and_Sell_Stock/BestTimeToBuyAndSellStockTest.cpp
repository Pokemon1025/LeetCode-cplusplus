//
// Created by 朱玥 on 2022/7/31.
//

#include "BestTimeToBuyAndSellStock.h"
#include <gtest/gtest.h>

class BestTimeToBuyAndSellStockTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(BestTimeToBuyAndSellStockTest, TestSolution01) {
  Solution01 s;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(5, s.maxProfit(nums));
}

TEST(BestTimeToBuyAndSellStockTest, TestSolution02) {
  Solution02 s;
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  EXPECT_EQ(5, s.maxProfit(nums));
}