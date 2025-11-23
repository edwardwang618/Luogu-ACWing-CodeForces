/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& a) {
    int n = a.size();
    int f[n], g[n], res;
    res = g[0] = f[0] = a[0];
    for (int i = 1; i < n; i++) {
      if (a[i] > 0) {
        f[i] = max(a[i], f[i - 1] * a[i]);
        g[i] = min(a[i], g[i - 1] * a[i]);
      } else {
        f[i] = max(a[i], g[i - 1] * a[i]);
        g[i] = min(a[i], f[i - 1] * a[i]);
      }

      res = max(res, f[i]);
    }

    return res;
  }
};
// @lc code=end
