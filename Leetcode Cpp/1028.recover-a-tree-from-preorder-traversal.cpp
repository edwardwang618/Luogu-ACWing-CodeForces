/*
 * @lc app=leetcode id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
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
  TreeNode* recoverFromPreorder(string s) {
    vector<TreeNode*> stk;
    for (int i = 0; i < s.size(); i++) {
      int j = i;
      while (j < s.size() && s[j] == '-') j++;
      int dep = j - i;
      while (stk.size() > dep) stk.pop_back();
      i = j;
      while (j < s.size() && isdigit(s[j])) j++;
      auto x = new TreeNode(stoi(s.substr(i, j - i)));
      if (stk.size())
        (!stk.back()->left ? stk.back()->left : stk.back()->right) = x;
      stk.push_back(x);
      i = j - 1;
    }

    return stk.front();
  }
};
// @lc code=end
