/*
 * @lc app=leetcode id=2196 lang=cpp
 *
 * [2196] Create Binary Tree From Descriptions
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
  TreeNode *createBinaryTree(vector<vector<int>> &ds) {
    unordered_map<int, TreeNode *> mp;
    unordered_set<TreeNode *> child;
    for (auto &v : ds) {
      int p = v[0], c = v[1], is_left = v[2];
      auto &pp = mp[p], &cc = mp[c];
      if (!pp)
        pp = new TreeNode(p);
      if (!cc)
        cc = new TreeNode(c);
      (is_left ? pp->left : pp->right) = cc;
      child.insert(cc);
    }
    for (auto [k, v] : mp)
      if (!child.count(v))
        return v;
    return nullptr;
  }
};
// @lc code=end
