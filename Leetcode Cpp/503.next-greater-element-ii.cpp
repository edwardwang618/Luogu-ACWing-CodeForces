/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &a) {
    int n = a.size();
    vector<int> res(n, -1);
    stack<int> stk;
    for (int i = 0; i < 2 * n - 1; i++) {
      int idx = i % n;
      while (stk.size() && a[stk.top()] < a[idx]) {
        res[stk.top()] = a[idx];
        stk.pop();
      }
      stk.push(idx);
    }

    return res;
  }
};
// @lc code=end
