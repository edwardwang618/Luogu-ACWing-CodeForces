/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
  int deepestLeavesSum(TreeNode* root) {
    int max_dep = -1, res = 0;
    dfs(root, 0, max_dep, res);
    return res;
  }

  void dfs(TreeNode* p, int dep, int& max_dep, int& res) {
    if (!p) return;
    if (!p->left && !p->right) {
      if (dep > max_dep) {
        res = p->val;
        max_dep = dep;
      } else if (dep == max_dep)
        res += p->val;
    }
    dfs(p->left, dep + 1, max_dep, res);
    dfs(p->right, dep + 1, max_dep, res);
  }
};
// @lc code=end
