/*
 * @lc app=leetcode id=545 lang=cpp
 *
 * [545] Boundary of Binary Tree
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
  vector<int> boundaryOfBinaryTree(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    res.push_back(root->val);

    auto dfs = [&](this auto &&dfs, auto *p, bool lb, bool rb) -> void {
      if (!p) return;
      if (!p->left && !p->right) {
        res.push_back(p->val);
        return;
      }
      if (lb) res.push_back(p->val);
      dfs(p->left, lb, rb && !p->right);
      dfs(p->right, lb && !p->left, rb);
      if (rb) res.push_back(p->val);
    };
    dfs(root->left, true, false);
    dfs(root->right, false, true);
    return res;
  }
};
// @lc code=end
