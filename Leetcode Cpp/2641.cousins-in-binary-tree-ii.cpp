/*
 * @lc app=leetcode id=2641 lang=cpp
 *
 * [2641] Cousins in Binary Tree II
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
  TreeNode *replaceValueInTree(TreeNode *root) {
    vector<int> levelSum;
    auto dfs1 = [&](this auto &&dfs1, TreeNode *p, int d) -> void {
      if (!p) return;
      if (d >= levelSum.size()) levelSum.emplace_back();
      levelSum[d] += p->val;
      dfs1(p->left, d + 1);
      dfs1(p->right, d + 1);
    };

    auto dfs2 = [&](this auto &&dfs2, TreeNode *p, int d) -> void {
      if (!p) return;
      int childSum = 0;
      if (p->left) childSum += p->left->val;
      if (p->right) childSum += p->right->val;
      if (p->left) p->left->val = levelSum[d + 1] - childSum;
      if (p->right) p->right->val = levelSum[d + 1] - childSum;
      dfs2(p->left, d + 1);
      dfs2(p->right, d + 1);
    };

    dfs1(root, 0);
    root->val = 0;
    dfs2(root, 0);
    return root;
  }
};
// @lc code=end
