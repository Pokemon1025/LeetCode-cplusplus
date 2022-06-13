//
// Created by 朱玥 on 2022/6/12.
//
#include <iostream>
#include <vector>

#include "222. Count_Complete_Tree_Nodes/countCompleteTreeNodes.h"

using namespace std;

int main()
{
  auto alg = new Solution();
  vector<int> data = {1, 2, 3, 4, 5, 6};
  TreeNode *root = alg->helper(data, 0);
  cout << alg->countNodes(root) << endl;
}

