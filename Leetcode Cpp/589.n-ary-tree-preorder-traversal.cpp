/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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

class Solution {
public:
  // vector<int> preorder(Node *root) {
  //   vector<int> res;
  //   auto dfs = [&](auto &&self, auto root) -> void {
  //     if (!root) return;
  //     res.push_back(root->val);
  //     for (auto p : root->children) self(self, p);
  //   };
  //   dfs(dfs, root);
  //   return res;
  // }

  vector<int> preorder(Node *root) {
    vector<int> res;
    stack<Node*> stk;
    if (!root) return res;
    stk.push(root);
    while (stk.size()) {
      auto p = stk.top(); stk.pop();
      res.push_back(p->val);
      int n = p->children.size();
      for (int i = n - 1; i >= 0; i--)
        stk.push(p->children[i]);
    }
    return res;
  }
};
// @lc code=end
