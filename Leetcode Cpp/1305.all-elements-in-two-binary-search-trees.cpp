/*
 * @lc app=leetcode id=1305 lang=cpp
 *
 * [1305] All Elements in Two Binary Search Trees
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
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> res;
    stack<TreeNode*> stk1, stk2;
    push_left(stk1, root1);
    push_left(stk2, root2);
    while (stk1.size() || stk2.size()) {
      if (stk1.empty() || stk2.size() && stk1.top()->val > stk2.top()->val)
        swap(stk1, stk2);
      auto t = stk1.top();
      stk1.pop();
      res.push_back(t->val);
      push_left(stk1, t->right);
    }
    return res;
  }

  void push_left(stack<TreeNode*>& stk, TreeNode* cur) {
    while (cur) {
      stk.push(cur);
      cur = cur->left;
    }
  }
};
// @lc code=end
