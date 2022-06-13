//
// Created by 朱玥 on 2022/6/13.
//

#pragma once
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;

//二叉数的节点有三个域：数据域和两个指针域
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {}
};

class Solution {
public:
  int countNodes(TreeNode *root) {
    if (root == nullptr)
      return 0;
    //完全二叉树的高度可以通过迭代访问左子树获取
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);
    if (lh == rh)//判断左右子树的高度，若相等左子树为满二叉树，进一步判断右子树节点数
      return (1 << lh) + countNodes(root->right);
    else//不等说明右子树是深度小于左子树的满二叉树, 然后进一步判断左子树的节点数
      return (1 << (lh - 1)) + countNodes(root->left);
  }

  // 以递归方式根据层序遍历构建二叉树
  TreeNode *helper(const vector<int> &data, int idx) {
    if (idx >= data.size() || data[idx] == '#')
      return nullptr;

    auto *root = new TreeNode(data[idx]);
    root->left = helper(data, 2 * idx + 1);  // 找到该节点的左子树
    root->right = helper(data, 2 * idx + 2); // 找到该节点的右子树
    return root;
  }

private:
  int treeHeight(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + treeHeight(root->left);
  }
};
