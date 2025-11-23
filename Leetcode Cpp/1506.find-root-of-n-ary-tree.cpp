/*
 * @lc app=leetcode id=1506 lang=cpp
 *
 * [1506] Find Root of N-Ary Tree
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
  Node *findRoot(vector<Node *> tree) {
    unordered_set<int> st;
    for (auto *tr : tree)
      for (auto *child : tr->children) st.insert(child->val);

    for (auto &tr : tree)
      if (!st.count(tr->val)) return tr;
    return nullptr;
  }
};
// @lc code=end
