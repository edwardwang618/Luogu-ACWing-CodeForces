/*
 * @lc app=leetcode id=250 lang=cpp
 *
 * [250] Count Univalue Subtrees
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
  int countUnivalSubtrees(TreeNode *root) {
    int res = 0;
    auto dfs = [&](this auto &&dfs, auto *p) -> bool {
      if (!p) return 0;
      bool is_uni = true;
      if (p->left) is_uni &= dfs(p->left) && p->val == p->left->val;
      if (p->right) is_uni &= dfs(p->right) && p->val == p->right->val;
      res += is_uni;
      return is_uni;
    };
    dfs(root);
    return res;
  }
};
// @lc code=end
