/*
 * @lc app=leetcode id=431 lang=cpp
 *
 * [431] Encode N-ary Tree to Binary Tree
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
 public:
  // Encodes an n-ary tree to a binary tree.
  TreeNode *encode(Node *root) {
    if (!root) return nullptr;
    TreeNode *r = new TreeNode(root->val);
    if (root->children.empty()) return r;
    r->left = encode(root->children[0]);
    auto *p = r->left;
    for (int i = 1; i < root->children.size(); i++) {
      p->right = encode(root->children[i]);
      p = p->right;
    }
    return r;
  }

  // Decodes your binary tree to an n-ary tree.
  Node *decode(TreeNode *root) {
    if (!root) return nullptr;
    Node *r = new Node(root->val);
    if (!root->left) return r;
    for (auto *p = root->left; p; p = p->right)
      r->children.push_back(decode(p));
    return r;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));
// @lc code=end
