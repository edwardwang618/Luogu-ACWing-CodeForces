/*
 * @lc app=leetcode id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
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
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> res;
    unordered_set<int> st(to_delete.begin(), to_delete.end());
    dfs(root, nullptr, st, res);
    return res;
  }

  TreeNode* dfs(TreeNode* p, TreeNode* pa, auto& st, auto& res) {
    if (!p) return nullptr;
    p->left = dfs(p->left, p, st, res);
    p->right = dfs(p->right, p, st, res);
    if (st.count(p->val)) return nullptr;
    if (!pa || st.count(pa->val)) res.push_back(p);
    return p;
  }
};
// @lc code=end
