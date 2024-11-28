/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     string val；
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */
class Solution {
 public:
  string expressionTree(TreeNode* root) {
    string res;
    dfs(root, res);
    return res.substr(1, res.size() - 2);
  }

  void dfs(auto p, string& res) {
    if (!p) return;
    static unordered_set<char> st{'+', '-', '*', '/'};
    if (st.count(p->val[0])) res += '(';
    dfs(p->left, res);
    res += p->val;
    dfs(p->right, res);
    if (st.count(p->val[0])) res += ')';
  }
};
