/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
 public:
  // int largestRectangleArea(vector<int>& hs) {
  //   int res = 0;
  //   stack<int> stk;
  //   for (int i = 0; i < hs.size(); i++) {
  //     while (stk.size() && hs[i] < hs[stk.top()]) {
  //       int h = hs[stk.top()];
  //       stk.pop();
  //       int l = stk.size() ? stk.top() : -1, r = i;
  //       res = max(res, h * (r - l - 1));
  //     }
  //     stk.push(i);
  //   }
  //   while (stk.size()) {
  //     int h = hs[stk.top()];
  //     stk.pop();
  //     int l = stk.size() ? stk.top() : -1, r = hs.size();
  //     res = max(res, h * (r - l - 1));
  //   }
  //   return res;
  // }

  struct Node {
    int val;
    Node *left, *right;
    Node() = default;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
  };
  int largestRectangleArea(vector<int>& hs) {
    int res = 0;
    auto root = build(hs);
    dfs(root, res);
    return res;
  }

  int dfs(auto p, int& res) {
    if (!p) return 0;
    int l = dfs(p->left, res), r = dfs(p->right, res);
    res = max(res, (1 + l + r) * p->val);
    return 1 + l + r;
  }

  Node* build(auto& hs) {
    vector<Node*> stk;
    for (int x : hs) {
      Node* last = nullptr;
      while (stk.size() && stk.back()->val > x) {
        last = stk.back();
        stk.pop_back();
      }
      auto p = new Node(x);
      p->left = last;
      if (stk.size()) stk.back()->right = p;
      stk.push_back(p);
    }
    return stk[0];
  }
};
// @lc code=end
