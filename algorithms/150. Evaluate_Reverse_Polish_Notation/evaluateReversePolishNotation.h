//
// Created by 朱玥 on 2022/6/15.
//

#pragma once
#include <stack>
#include <string>
#include <vector>
using namespace std;
// 逆波兰式是一种后缀表达式，其优点主要有两个方面：
// (1)去掉括号后表达式无歧义，上式即便写成 1 2 + 3 4 + * 也可以依据次序计算出正确结果。
// (2)适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中。

// 思路:栈与递归可转换，递归是用栈实现的;展现了计算机的思考方式
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> stack;
    for (const auto & token : tokens) {
      if (token == "*" || token == "/" || token == "+" ||
          token == "-") {
        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();
        if (token == "*") stack.push(num2 * num1);
        if (token == "/") stack.push(num2 / num1);
        if (token == "+") stack.push(num2 + num1);
        if (token == "-") stack.push(num2 - num1);
      } else {
        stack.push(stoi(token));
      }
    }
    return stack.top();
  }
};