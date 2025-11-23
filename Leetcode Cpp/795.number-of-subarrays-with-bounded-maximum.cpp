/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */

// @lc code=start
class Solution {
 public:
  int numSubarrayBoundedMax(vector<int>& a, int l, int r) {
    int res = 0, n = a.size();
    stack<int> stk;
    for (int i = 0; i < n; i++) {
      while (stk.size() && a[stk.top()] < a[i]) {
        int t = stk.top(); stk.pop();
        int lc = t - (stk.empty() ? -1 : stk.top()), rc = i - t;
        if (l <= a[t] && a[t] <= r) res += lc * rc;
      }

      stk.push(i);
    }
    while (stk.size()) {
        int t = stk.top(); stk.pop();
        int lc = t - (stk.empty() ? -1 : stk.top()), rc = n - t;
        if (l <= a[t] && a[t] <= r) res += lc * rc;
    }

    return res;
  }
};
// @lc code=end
