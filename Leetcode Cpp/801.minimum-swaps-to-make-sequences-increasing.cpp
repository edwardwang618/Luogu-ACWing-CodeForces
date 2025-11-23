/*
 * @lc app=leetcode id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

// @lc code=start
class Solution {
 public:
  int minSwap(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int f[n], g[n];
    memset(f, 0, sizeof f);
    memset(g, 0, sizeof g);
    g[0] = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1] && b[i] > b[i - 1]) {
        if (a[i] > b[i - 1] && b[i] > a[i - 1]) {
          f[i] = min(f[i - 1], g[i - 1]);
          g[i] = min(f[i - 1], g[i - 1]) + 1;
        } else {
          f[i] = f[i - 1];
          g[i] = g[i - 1] + 1;
        }
      } else {
        f[i] = g[i - 1];
        g[i] = f[i - 1] + 1;
      }
    }

    return min(f[n - 1], g[n - 1]);
  }
};
// @lc code=end
