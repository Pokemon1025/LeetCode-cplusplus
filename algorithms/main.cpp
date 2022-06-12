//
// Created by 朱玥 on 2022/6/12.
//
#include <iostream>
#include <vector>

#include "121. Best_Time_to_Buy_and_Sell_Stock/bestTimeToBuyAndSellStock.h"

using namespace std;

int main()
{
  vector<int> prices = {7,1,5,3,6,4};

  auto alg = new Solution();
  cout << alg->maxProfit(prices) << endl;

}
