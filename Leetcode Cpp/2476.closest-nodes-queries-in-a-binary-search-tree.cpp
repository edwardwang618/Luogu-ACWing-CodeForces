/*
 * @lc app=leetcode id=2476 lang=cpp
 *
 * [2476] Closest Nodes Queries in a Binary Search Tree
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
  vector<vector<int>> closestNodes(TreeNode *root, vector<int> &qs) {
    vector<int> v;
    auto dfs = [&](this auto &&dfs, auto *p) -> void {
      if (!p)
        return;
      dfs(p->left);
      v.push_back(p->val);
      dfs(p->right);
    };
    dfs(root);

    vector<vector<int>> res;
    res.reserve(qs.size());
    for (int q : qs) {
      auto it = lower_bound(v.begin(), v.end(), q);
      int r = it == v.end() ? -1 : *it;
      int l = r == q ? q : it == v.begin() ? -1 : *prev(it);
      res.push_back({l, r});
    }
    return res;
  }
};
// @lc code=end
