/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &a) {
    vector<TreeNode*> stk;
    for (int x : a) {
      auto cur = new TreeNode(x);
      while (stk.size() && stk.back()->val < x) {
        cur->left = stk.back();
        stk.pop_back();
      }
      if (stk.size()) stk.back()->right = cur;
      stk.push_back(cur);
    }
    return stk.front();
  }
};
// @lc code=end
