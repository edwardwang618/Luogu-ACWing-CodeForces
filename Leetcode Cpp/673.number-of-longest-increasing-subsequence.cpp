/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
 public:
  int findNumberOfLIS(vector<int>& a) {
    int n = a.size();
    vector<int> f(n), g(n);
    int max_len = 0;
    for (int i = 0; i < n; i++) {
      f[i] = g[i] = 1;
      for (int j = 0; j < i; j++)
        if (a[j] < a[i]) {
          if (f[j] + 1 > f[i]) {
            f[i] = f[j] + 1;
            g[i] = g[j];
          } else if (f[j] + 1 == f[i])
            g[i] += g[j];
        }

      max_len = max(max_len, f[i]);
    }

    int res = 0;
    for (int i = 0; i < n; i++)
      if (f[i] == max_len) res += g[i];
    return res;
  }
};
// @lc code=end
