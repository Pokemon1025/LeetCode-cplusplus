//
// Created by 朱玥 on 2022/6/12.
//
#include <iostream>
#include <vector>

#include "150. Evaluate_Reverse_Polish_Notation/evaluateReversePolishNotation.h"

using namespace std;

int main()
{
  auto alg = new Solution();
  vector<string> tokens = {"10", "6", "9",  "3", "+", "-11", "*",
                           "/",  "*", "17", "+", "5", "+"};
  cout << alg->evalRPN(tokens) << endl;
}

