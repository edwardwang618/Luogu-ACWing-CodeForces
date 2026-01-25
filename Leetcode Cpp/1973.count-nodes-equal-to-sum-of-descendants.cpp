/*
 * @lc app=leetcode id=1973 lang=cpp
 *
 * [1973] Count Nodes Equal to Sum of Descendants
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
  int equalToDescendants(TreeNode *root) {
    int res = 0;
    using ll = long long;
    auto dfs = [&](this auto &&dfs, TreeNode *p) -> ll {
      if (!p)
        return 0;
      ll sum = dfs(p->left) + dfs(p->right);
      if (sum == p->val)
        res++;
      return sum + p->val;
    };
    dfs(root);
    return res;
  }
};
// @lc code=end
