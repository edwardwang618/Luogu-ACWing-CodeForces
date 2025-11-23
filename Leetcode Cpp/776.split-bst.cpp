/*
 * @lc app=leetcode id=776 lang=cpp
 *
 * [776] Split BST
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
  vector<TreeNode*> splitBST(TreeNode* root, int t) {
    if (!root) return {nullptr, nullptr};
    if (root->val <= t) {
      auto res = splitBST(root->right, t);
      root->right = res[0];
      return {root, res[1]};
    } else {
      auto res = splitBST(root->left, t);
      root->left = res[1];
      return {res[0], root};
    }
  }
};
// @lc code=end
