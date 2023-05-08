//
// Created by 朱玥 on 2023/5/8.
//

#include "twoSum.h"
#include <gtest/gtest.h>

class TwoSumTest : public testing::Test {
protected:
  void TearDown() override {}
  void SetUp() override {}
};

TEST(TwoSumTest, TestSolution) {
  Solution s;
  vector<int> num = {3,2,4};
  int target = 6;
  auto res =s.twoSum(num, target);
  vector<int> res_target = {1,2};
  EXPECT_EQ(res, res_target);
}