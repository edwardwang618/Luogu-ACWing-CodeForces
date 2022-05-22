#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* convert(TreeNode* root) {
    stack<TreeNode*> stk;
    auto dummy = new TreeNode(0), prev = dummy;
    while (stk.size() || root) {
      while (root) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top(); stk.pop();
      prev->right = root;
      root->left = prev;
      prev = prev->right;

      root = root->right;
    }

    root = dummy->right;
    dummy->right = nullptr;
    if (root) root->left = nullptr;
    return root;
  }
};