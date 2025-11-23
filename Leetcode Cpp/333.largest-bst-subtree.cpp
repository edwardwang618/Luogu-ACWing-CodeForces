/*
 * @lc app=leetcode id=333 lang=cpp
 *
 * [333] Largest BST Subtree
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
  int largestBSTSubtree(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;
  }

  struct Node {
    int cnt, m, M;
  };

  Node dfs(auto cur, int& res) {
    if (!cur) return {0, 0, 0};
    auto l = dfs(cur->left, res), r = dfs(cur->right, res);
    if (!~l.cnt || !~r.cnt) return {-1, 0, 0};
    if ((!cur->left || cur->val > l.M) && (!cur->right || cur->val < r.m)) {
      res = max(res, 1 + l.cnt + r.cnt);
      int m, M;
      m = M = cur->val;
      if (cur->left) m = l.m;
      if (cur->right) M = r.M;
      return {1 + l.cnt + r.cnt, m, M};
    }
    return {-1, 0, 0};
  }
};
// @lc code=end
