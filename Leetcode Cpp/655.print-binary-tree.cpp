/*
 * @lc app=leetcode id=655 lang=cpp
 *
 * [655] Print Binary Tree
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
  vector<vector<string>> printTree(TreeNode *root) {
    auto f = [&](auto&& f, auto p) -> pair<int, int> {
      if (!p) return {0, 0};
      auto [lh, lw] = f(f, p->left);
      auto [rh, rw] = f(f, p->right);
      return {1 + max(lh, rh), max(lw, rw) * 2 + 1};
    };
    auto [h, w] = f(f, root);
    vector<vector<string>> res(h, vector<string>(w, ""));
    dfs(root, 0, 0, (1 << h) - 1, res);
    return res;
  }

  static void dfs(auto p, int dep, int l, int r, auto& res) {
    if (!p) return;
    int mid = l + r >> 1;
    res[dep][mid] = to_string(p->val);
    dfs(p->left, dep + 1, l, mid - 1, res);
    dfs(p->right, dep + 1, mid + 1, r, res);
  }
};
// @lc code=end
