/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &ps) {
    int n = ps.size();
    vector<int> f(n);
    for (int i = 1, m = ps[0]; i < n; i++) {
      f[i] = max(f[i - 1], ps[i] - m);
      m = min(m, ps[i]);
    }
    int res = 0;
    for (int i = n - 1, mx = 0; i >= 0; i--) {
      res = max(res, mx - ps[i] + f[i]);
      mx = max(mx, ps[i]);
    }
    return res;
  }
};
// @lc code=end
