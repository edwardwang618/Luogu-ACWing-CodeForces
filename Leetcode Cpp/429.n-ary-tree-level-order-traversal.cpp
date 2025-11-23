/*
 * @lc app=leetcode id=429 lang=cpp
 *
 * [429] N-ary Tree Level Order Traversal
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
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<Node*> q;
    q.push(root);
    while (q.size()) {
      vector<int> v;
      for (int i = q.size(); i; i--) {
        auto t = q.front();
        q.pop();
        v.push_back(t->val);
        for (auto* node : t->children) q.push(node);
      }
      res.push_back(v);
    }

    return res;
  }
};
// @lc code=end
