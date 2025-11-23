/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
// class Solution {
//  public:
//   TreeNode* deleteNode(TreeNode* root, int key) {
//     if (!root) return nullptr;
//     if (key < root->val) root->left = deleteNode(root->left, key);
//     else if (key > root->val) root->right = deleteNode(root->right, key);
//     else root = merge(root->left, root->right);
//     return root;
//   }

//   TreeNode* merge(TreeNode* p1, TreeNode* p2) {
//     if (!p1) return p2;
//     if (!p2) return p1;
//     if ((p1->val ^ p2->val) & 1) {
//       p2->left = merge(p1, p2->left);
//       return p2;
//     } else {
//       p1->right = merge(p1->right, p2);
//       return p1;
//     }
//   }
// };

class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
      if (root->left) {
        root = zig(root);
        root->right = deleteNode(root->right, key);
      } else if (root->right) {
        root = zag(root);
        root->left = deleteNode(root->left, key);
      } else root = nullptr;
    }
    return root;
  }

  TreeNode* zig(TreeNode* p) {
    auto* q = p->left;
    p->left = q->right;
    q->right = p;
    return q;
  }

  TreeNode* zag(TreeNode* p) {
    auto* q = p->right;
    p->right = q->left;
    q->left = p;
    return q;
  }
};
// @lc code=end
