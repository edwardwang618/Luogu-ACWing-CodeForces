#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> mp;
    int n = inorder.size();
    for (int i = 0; i < n; i++) mp[inorder[i]] = i;
    return dfs(preorder, 0, n - 1, inorder, 0, n - 1, mp);
  }

  TreeNode* dfs(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir, unordered_map<int, int>& mp) {
    if (pl > pr) return nullptr;
    if (pl == pr) return new TreeNode(preorder[pl]);
    int idx = mp[preorder[pl]];
    int ls = idx - il, rs = ir - idx;
    TreeNode* root = new TreeNode(preorder[pl]);
    root->left = dfs(preorder, pl + 1, pl + ls, inorder, il, idx - 1, mp);
    root->right = dfs(preorder, pl + ls + 1, pr, inorder, idx + 1, ir, mp);
    return root;
  }
};