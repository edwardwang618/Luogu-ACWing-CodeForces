/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& a) {
    int n = a.size();
    stack<int> stk;
    int l = n, r = 0;
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.top()] > a[i]) {
        l = min(l, stk.top());
        stk.pop();
      }
      stk.push(i);
    }
    if (l == n) return 0;
    stack<int>().swap(stk);
    for (int i = n - 1; i >= 0; i--) {
      while (stk.size() && a[stk.top()] < a[i]) {
        r = max(r, stk.top());
        stk.pop();
      }
      stk.push(i);
    }
    return r - l + 1;
  }
};
// @lc code=end
