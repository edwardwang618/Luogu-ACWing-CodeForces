/*
 * @lc app=leetcode id=1214 lang=cpp
 *
 * [1214] Two Sum BSTs
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
  struct Ite {
    stack<TreeNode *> stk;
    bool desc;

    Ite(TreeNode *root, bool desc) : desc(desc) {
      while (root) {
        stk.push(root);
        root = !desc ? root->left : root->right;
      }
    }

    operator bool() { return stk.size(); }

    int operator*() { return stk.top()->val; }

    Ite &operator++() {
      auto t = stk.top(); stk.pop();
      if (!desc) {
        auto right = t->right;
        while (right) {
          stk.push(right);
          right = right->left;
        }
      } else {
        auto left = t->left;
        while (left) {
          stk.push(left);
          left = left->right;
        }
      }

      return *this;
    }
  };

  bool twoSumBSTs(TreeNode *r1, TreeNode *r2, int t) {
    Ite it1(r1, false), it2(r2, true);
    while (it1 && it2) {
      int x1 = *it1, x2 = *it2;
      if (x1 + x2 < t) ++it1;
      else if (x1 + x2 > t) ++it2;
      else return true;
    }

    return false;
  }
};
// @lc code=end
