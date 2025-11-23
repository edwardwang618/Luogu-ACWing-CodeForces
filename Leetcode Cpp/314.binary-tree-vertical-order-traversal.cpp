/*
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
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
  using PTI = pair<TreeNode*, int>;
  vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;

    unordered_map<int, vector<int>> mp;
    queue<PTI> q;
    q.push({root, 0});
    int min_col = 0;
    while (q.size()) {
      auto p = q.front(); q.pop();
      min_col = min(min_col, p.second);
      auto* t = p.first;
      mp[p.second].push_back(t->val);
      if (t->left) q.push({t->left, p.second - 1});
      if (t->right) q.push({t->right, p.second + 1});
    }
    res.resize(mp.size());
    for (auto& [k, v] : mp) res[k - min_col].swap(v);
    return res;
  }
};
// @lc code=end
