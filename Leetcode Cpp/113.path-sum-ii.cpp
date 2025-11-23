/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
  vector<vector<int>> pathSum(TreeNode* root, int t) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(root, 0, t, path, res);
    return res;
  }

  void dfs(auto p, int sum, int t, auto& path, auto& res) {
    if (!p) return;
    sum += p->val;
    path.push_back(p->val);
    if (!p->left && !p->right) {
      if (sum == t) res.push_back(path);
    } else {
      dfs(p->left, sum, t, path, res);
      dfs(p->right, sum, t, path, res);
    }
    path.pop_back();
  }
};
// @lc code=end
