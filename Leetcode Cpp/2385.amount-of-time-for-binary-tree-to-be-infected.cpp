/*
 * @lc app=leetcode id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
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
  int amountOfTime(TreeNode *root, int x) {
    int res = 0;
    auto dfs = [&](this auto &&dfs, auto *p) -> pair<int, int> {
      if (!p) return {-1, 0};
      auto [ldis, ldepth] = dfs(p->left);
      auto [rdis,rdepth] = dfs(p->right);
      int depth = max(ldepth, rdepth) + 1;
      if (p->val == x) {
        res = max(res, max(ldepth, rdepth));
        return {0, depth};
      }
      if (ldis >= 0) {
        res = max(res, ldis + 1 + rdepth);
        return {ldis + 1, depth};
      }
      if (rdis >= 0) {
        res = max(res, rdis + 1 + ldepth);
        return {rdis + 1, depth};
      }

      return {-1, depth};
    };
    dfs(root);
    return res;
  }
};
// @lc code=end
