#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int>> printFromTopToBottom(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;
    bool rev = false;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size()) {
      vector<int> row;
      for (int i = q.size(); i; i--) {
        auto t = q.front(); q.pop();
        row.push_back(t->val);
        if (t->left) q.push(t->left);
        if (t->right) q.push(t->right);
      }
      if (rev) reverse(row.begin(), row.end());
      res.push_back(row);
      rev = !rev;
    }

    return res;
  }
};