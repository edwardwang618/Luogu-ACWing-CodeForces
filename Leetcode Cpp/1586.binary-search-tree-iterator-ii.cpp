/*
 * @lc app=leetcode id=1586 lang=cpp
 *
 * [1586] Binary Search Tree Iterator II
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
class BSTIterator {
 public:
  stack<TreeNode*> stk;
  vector<int> v;
  int idx;
  BSTIterator(TreeNode* root) {
    idx = -1;
    while (root) {
      stk.push(root);
      root = root->left;
    }
  }

  bool hasNext() { return idx + 1 < v.size() || stk.size(); }

  int next() {
    if (++idx == v.size()) {
      auto p = stk.top();
      stk.pop();
      v.push_back(p->val);
      p = p->right;
      while (p) {
        stk.push(p);
        p = p->left;
      }
    }
    return v[idx];
  }

  bool hasPrev() { return idx > 0; }

  int prev() { return v[--idx]; }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
// @lc code=end
