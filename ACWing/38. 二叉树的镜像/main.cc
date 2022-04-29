struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void mirror(TreeNode* root) {
      if (!root) return;
      swap(root->left, root->right);
      mirror(root->left), mirror(root->right);
    }
};