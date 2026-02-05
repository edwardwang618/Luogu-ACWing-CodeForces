/*
 * @lc app=leetcode id=255 lang=cpp
 *
 * [255] Verify Preorder Sequence in Binary Search Tree
 */

// @lc code=start
class Solution {
public:
  // bool verifyPreorder(vector<int> &pre) {
  //   int idx = 0;
  //   auto dfs = [&](this auto &&dfs, int min, int max) -> void {
  //     if (idx == pre.size())
  //       return;
  //     int x = pre[idx];
  //     if (min < x && x < max) {
  //       idx++;
  //       dfs(min, x);
  //       dfs(x, max);
  //     }
  //   };
  //   dfs(INT_MIN, INT_MAX);
  //   return idx == pre.size();
  // }

  bool verifyPreorder(vector<int> &pre) {
    stack<int> stk;
    int min = INT_MIN;
    for (int x : pre) {
      if (x < min) return false;
      while (stk.size() && stk.top() < x) {
        min = stk.top();
        stk.pop();
      }
      stk.push(x);
    }
    return true;
  }
};
// @lc code=end
