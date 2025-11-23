/*
 * @lc app=leetcode id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
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
  TreeNode* lcaDeepestLeaves(TreeNode* root) { return dfs(root).second; }

  pair<int, TreeNode*> dfs(TreeNode* root) {
    if (!root) return {0, nullptr};
    auto l = dfs(root->left), r = dfs(root->right);
    if (l.first > r.first)
      return {l.first + 1, l.second};
    else if (l.first < r.first)
      return {r.first + 1, r.second};
    else
      return {l.first + 1, root};
  }
};
// @lc code=end
