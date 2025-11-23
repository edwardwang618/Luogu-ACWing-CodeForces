/*
 * @lc app=leetcode id=1644 lang=cpp
 *
 * [1644] Lowest Common Ancestor of a Binary Tree II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int mark = 0;
    auto res = dfs(root, p, q, mark);
    if (mark != 3) return nullptr;
    return res;
  }

  TreeNode* dfs(auto root, auto p, auto q, int& mark) {
    if (!root) return nullptr;
    auto l = dfs(root->left, p, q, mark), r = dfs(root->right, p, q, mark);
    if (root == p) {
      mark |= 1;
      return root;
    }
    if (root == q) {
      mark |= 2;
      return root;
    }

    if (l && r) return root;
    return l ? l : r;
  }
};
// @lc code=end
