/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
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
  TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
    int n = pre.size();
    vector<int> pre_pos(n + 1), post_pos(n + 1);
    for (int i = 0; i < n; i++)
      pre_pos[pre[i]] = i, post_pos[post[i]] = i;

    auto dfs = [&](auto &&self, int l1, int r1, int l2, int r2) -> TreeNode * {
      if (l1 > r1)
        return nullptr;
      if (l1 == r1)
        return new TreeNode(pre[l1]);
      int lroot = pre[l1 + 1], rroot = post[r2 - 1];
      return new TreeNode(
          pre[l1], self(self, l1 + 1, pre_pos[rroot] - 1, l2, post_pos[lroot]),
          self(self, pre_pos[rroot], r1, post_pos[lroot] + 1, r2 - 1));
    };
    return dfs(dfs, 0, n - 1, 0, n - 1);
  }
};
// @lc code=end
