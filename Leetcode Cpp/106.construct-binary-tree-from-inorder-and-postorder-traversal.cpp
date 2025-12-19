/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
  TreeNode *buildTree(vector<int> &in, vector<int> &post) {
    int n = in.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
      mp[in[i]] = i;
    return dfs(0, n - 1, 0, n - 1, in, post, mp);
  }

  static TreeNode *dfs(int l1, int r1, int l2, int r2, auto &in, auto &post,
                       auto &mp) {
    if (l1 > r1)
      return nullptr;
    auto root = new TreeNode(post[r2]);
    int idx = mp[root->val], len_l = idx - l1, len_r = r1 - idx;
    root->left = dfs(l1, idx - 1, l2, l2 + len_l - 1, in, post, mp);
    root->right = dfs(idx + 1, r1, r2 - len_r, r2 - 1, in, post, mp);
    return root;
  }
};
// @lc code=end
