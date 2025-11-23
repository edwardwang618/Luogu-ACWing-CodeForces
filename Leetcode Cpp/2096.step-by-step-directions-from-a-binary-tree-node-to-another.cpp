/*
 * @lc app=leetcode id=2096 lang=cpp
 *
 * [2096] Step-By-Step Directions From a Binary Tree Node to Another
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
  string getDirections(TreeNode* root, int startValue, int destValue) {
    string p1, p2;
    dfs(root, p1, startValue);
    dfs(root, p2, destValue);
    int idx = 0;
    while (p1[idx] == p2[idx]) idx++;
    return string(p1.size() - idx, 'U') + p2.substr(idx);
  }

  bool dfs(TreeNode* cur, string& path, int val) {
    if (!cur) return false;
    if (cur->val == val) return true;
    path += 'L';
    if (dfs(cur->left, path, val)) return true;
    path.back() = 'R';
    if (dfs(cur->right, path, val)) return true;
    path.pop_back();
    return false;
  }
};
// @lc code=end
