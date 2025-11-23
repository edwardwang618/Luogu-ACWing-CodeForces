/*
 * @lc app=leetcode id=1382 lang=cpp
 *
 * [1382] Balance a Binary Search Tree
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
  TreeNode* balanceBST(TreeNode* root) {
    vector<int> v;
    dfs1(root, v);
    for (auto x : v) cout << x << endl;
    return dfs2(v, 0, v.size() - 1);
  }

  void dfs1(TreeNode* cur, vector<int>& v) {
    if (!cur) return;
    dfs1(cur->left, v);
    v.push_back(cur->val);
    dfs1(cur->right, v);
  }

  TreeNode* dfs2(vector<int>& v, int l, int r) {
    if (l > r) return nullptr;
    int mid = l + (r - l >> 1);
    TreeNode* root = new TreeNode(v[mid], nullptr, nullptr);
    root->left = dfs2(v, l, mid - 1), root->right = dfs2(v, mid + 1, r);
    return root;
  }
};
// @lc code=end
