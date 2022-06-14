//
// Created by 朱玥 on 2022/6/12.
//
#include <iostream>
#include <vector>

#include "704. Binary_Search/binarySearch.h"

using namespace std;

int main()
{
  auto alg = new Solution02();
  vector<int> data = {-1, 0, 3, 5, 9, 12};
  cout << alg->search(data, 9) << endl;
}

