/*
 * @lc app=leetcode id=2334 lang=cpp
 *
 * [2334] Subarray With Elements Greater Than Varying Threshold
 */

// @lc code=start
class Solution {
 public:
  int validSubarraySize(vector<int>& a, int t) {
    stack<int> stk;
    int n = a.size();
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.top()] >= a[i]) {
        int idx = stk.top();
        stk.pop();
        int l = stk.size() ? stk.top() : -1;
        int len = i - l - 1;
        if (a[idx] > (double)t / len) return len;
      }
      stk.push(i);
    }
    while (stk.size()) {
      int idx = stk.top();
      stk.pop();
      int l = stk.size() ? stk.top() : -1;
      int len = n - l - 1;
      if (a[idx] > (double)t / len) return len;
    }
    return -1;
  }
};
// @lc code=end
