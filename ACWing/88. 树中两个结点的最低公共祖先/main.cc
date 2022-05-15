struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;
    if (root == p) return p;
    if (root == q) return q;

    auto l = lowestCommonAncestor(root->left, p, q);
    auto r = lowestCommonAncestor(root->right, p, q);
    if (!l) return r;
    if (!r) return l;
    return root;
  }
};