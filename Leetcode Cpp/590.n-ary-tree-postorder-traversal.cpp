/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
  // vector<int> postorder(Node *root) {
  //   vector<int> res;
  //   auto dfs = [&](auto &&self, auto root) -> void {
  //     if (!root) return;
  //     for (auto p : root->children) self(self, p);
  //     res.push_back(root->val);
  //   };
  //   dfs(dfs, root);
  //   return res;
  // }

  vector<int> postorder(Node *root) {
    vector<int> res;
    if (!root) return res;
    stack<Node*> stk;
    stk.push(root);
    Node *last = nullptr;
    while (stk.size()) {
      auto p = stk.top();
      int n = p->children.size();
      if (!n || last && p->children.back() == last) {
        res.push_back(p->val);
        stk.pop();
        last = p;
      } else {
        for (int i = n - 1; i >= 0; i--)
          stk.push(p->children[i]);
      }
    }
    return res;
  }
};
// @lc code=end
