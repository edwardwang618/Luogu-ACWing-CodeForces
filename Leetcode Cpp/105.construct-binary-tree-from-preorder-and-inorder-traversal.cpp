
/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
  TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
    unordered_map<int, int> mp;
    int n = in.size();
    for (int i = 0; i < n; i++) mp[in[i]] = i;
    return dfs(pre, 0, n - 1, in, 0, n - 1, mp);
  }

  TreeNode* dfs(auto& pre, int b1, int e1, auto& in, int b2, int e2, auto& mp) {
    if (b1 > e1) return nullptr;
    auto root = new TreeNode(pre[b1]);
    int idx = mp[root->val], sz_left = idx - b2;
    root->left = dfs(pre, b1 + 1, b1 + sz_left, in, b2, idx - 1, mp);
    root->right = dfs(pre, b1 + sz_left + 1, e1, in, idx + 1, e2, mp);
    return root;
  }
};
// @lc code=end
