/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
  // TreeNode* increasingBST(TreeNode* root) { return dfs(root).first; }

  // pair<TreeNode*, TreeNode*> dfs(TreeNode* root) {
  //   if (!root) return {nullptr, nullptr};
  //   TreeNode *l1, *r1, *l2, *r2;
  //   tie(l1, r1) = dfs(root->left);
  //   tie(l2, r2) = dfs(root->right);
  //   if (r1) r1->right = root;
  //   root->right = l2;
  //   root->left = nullptr;
  //   return {l1 ? l1 : root, r2 ? r2 : root};
  // }

  TreeNode* increasingBST(TreeNode* root) {
    TreeNode *dummy = new TreeNode(0), *cur = dummy;
    dfs(root, cur);
    return dummy->right;
  }

  void dfs(TreeNode* p, TreeNode*& cur) {
    if (!p) return;
    dfs(p->left, cur);
    cur->right = p;
    cur = p;
    cur->left = nullptr;
    dfs(p->right, cur);
  }
};
// @lc code=end
