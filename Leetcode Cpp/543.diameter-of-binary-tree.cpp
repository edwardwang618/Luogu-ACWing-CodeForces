/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
  int diameterOfBinaryTree(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res - 1;
  }

  int dfs(auto p, int& res) {
    if (!p) return 0;
    int l = dfs(p->left, res), r = dfs(p->right, res);
    res = max(res, 1 + l + r);
    return 1 + max(l, r);
  }
};
// @lc code=end
