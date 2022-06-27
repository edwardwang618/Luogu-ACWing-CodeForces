struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* kthNode(TreeNode* root, int k) {
    return dfs(root, k);
  }

  TreeNode* dfs(TreeNode* x, int& k) {
    if (!x) return nullptr;
    TreeNode* l = dfs(x->left, k);
    if (l) return l;
    if (!--k) return x;
    return dfs(x->right, k);
  }
};