/*
 * @lc app=leetcode id=536 lang=cpp
 *
 * [536] Construct Binary Tree from String
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
  // TreeNode* str2tree(string s) {
  //   int idx = 0;
  //   return dfs(idx, s);
  // }

  // TreeNode* dfs(int& idx, string& s) {
  //   if (idx == s.size()) return nullptr;
  //   int sign = 1;
  //   if (s[idx] == '-') sign = -1, idx++;
  //   int i = idx;
  //   while (idx < s.size() && isdigit(s[idx])) idx++;
  //   auto root = new TreeNode(sign * stoi(s.substr(i, idx - i)));
  //   if (idx < s.size() && s[idx] == '(') {
  //     idx++;
  //     root->left = dfs(idx, s);
  //     idx++;
  //   }

  //   if (idx < s.size() && s[idx] == '(') {
  //     idx++;
  //     root->right = dfs(idx, s);
  //     idx++;
  //   }
  //   return root;
  // }

  TreeNode* str2tree(string s) {
    stack<TreeNode*> stk;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '-' || isdigit(s[i])) {
        int sign = 1;
        if (s[i] == '-') sign = -1, i++;
        int j = i;
        while (i < s.size() && isdigit(s[i])) i++;
        auto node = new TreeNode(sign * stoi(s.substr(j, i - j)));
        i--;
        if (stk.size()) {
          if (!stk.top()->left)
            stk.top()->left = node;
          else
            stk.top()->right = node;
        }
        stk.push(node);
      } else if (s[i] == ')')
        stk.pop();
    }
    return stk.size() ? stk.top() : nullptr;
  }
};
// @lc code=end
