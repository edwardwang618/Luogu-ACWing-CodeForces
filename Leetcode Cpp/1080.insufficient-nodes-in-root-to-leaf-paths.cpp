/*
 * @lc app=leetcode id=1080 lang=cpp
 *
 * [1080] Insufficient Nodes in Root to Leaf Paths
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
  TreeNode *sufficientSubset(TreeNode *root, int limit) {
    auto dfs = [&](this auto &&dfs, auto *&p, int sum) -> int {
      if (!p) return 0;
      sum += p->val;
      if (!p->left && !p->right) {
        if (sum < limit) p = nullptr;
        return sum;
      }
      int sl = INT_MIN, sr = INT_MIN;
      if (p->left) sl = dfs(p->left, sum);
      if (p->right) sr = dfs(p->right, sum);
      int ms = max(sl, sr);
      if (ms < limit) p = nullptr;
      return ms;
    };
    dfs(root, 0);
    return root;
  }
};
// @lc code=end
