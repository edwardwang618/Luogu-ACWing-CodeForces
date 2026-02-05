/*
 * @lc app=leetcode id=2458 lang=cpp
 *
 * [2458] Height of Binary Tree After Subtree Removal Queries
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
  vector<int> treeQueries(TreeNode *root, vector<int> &qs) {
    unordered_map<TreeNode *, int> he;
    unordered_map<int, int> f;
    auto dfs1 = [&](this auto &&dfs1, auto *p) -> int {
      if (!p)
        return he[p] = -1;
      return he[p] = 1 + max(dfs1(p->left), dfs1(p->right));
    };
    dfs1(root);

    auto dfs2 = [&](this auto &&dfs2, auto *p, int dep, int res) -> void {
      if (!p)
        return;
      f[p->val] = res;
      dfs2(p->left, dep + 1, max(res, 1 + dep + he[p->right]));
      dfs2(p->right, dep + 1, max(res, 1 + dep + he[p->left]));
    };
    dfs2(root, 0, 0);
    vector<int> res;
    for (int x : qs)
      res.push_back(f[x]);
    return res;
  }
};
// @lc code=end
