/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
  int kthSmallest(TreeNode* root, int k) {
    int res;
    dfs(root, k, res);
    return res;
  }

  void dfs(auto* p, int& k, int& res) {
    if (!p) return;
    dfs(p->left, k, res);
    if (!--k) {
      res = p->val;
      return;
    }
    dfs(p->right, k, res);
  }
};
// @lc code=end
