/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
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
  using PII = pair<int, int>;
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<PII>> mp;
    dfs(root, mp, 0, 0);
    vector<vector<int>> res;
    for (auto& [k, v] : mp) {
      sort(v.begin(), v.end(), [&](auto& p1, auto& p2) {
        if (p1.first != p2.first) return p1.first < p2.first;
        return p1.second < p2.second;
      });
      res.push_back({});
      for (auto& w : v) res.back().push_back(w.second);
    }
    return res;
  }

  void dfs(TreeNode* p, map<int, vector<PII>>& mp, int x, int y) {
    if (!p) return;
    mp[y].push_back({x, p->val});
    dfs(p->left, mp, x + 1, y - 1);
    dfs(p->right, mp, x + 1, y + 1);
  }
};
// @lc code=end
