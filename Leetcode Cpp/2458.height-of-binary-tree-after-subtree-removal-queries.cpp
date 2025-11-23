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
  vector<int> treeQueries(TreeNode* root, vector<int>& qs) {
    unordered_map<TreeNode*, int> he;
    unordered_map<int, int> f;
    dfs1(root, he);
    dfs2(root, 0, 0, f, he);
    vector<int> res;
    for (int x : qs) res.push_back(f[x]);
    return res;
  }

  int dfs1(auto* p, auto& he) {
    if (!p) return he[p] = -1;
    return he[p] = 1 + max(dfs1(p->left, he), dfs1(p->right, he));
  }

  void dfs2(auto* p, int dep, int res, auto& f, auto& he) {
    if (!p) return;
    f[p->val] = res;
    dfs(p->left, dep + 1, max(res, 1 + dep + he[p->right]));
    dfs(p->right, dep + 1, max(res, 1 + dep + he[p->left]));
  }
};
// @lc code=end
