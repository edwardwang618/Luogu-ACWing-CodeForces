/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
  int findTargetSumWays(vector<int> &a, int t) {
    int n = a.size(), sum = 0;
    for (int x : a)
      sum += x;
    if (sum + t & 1 || sum + t < 0)
      return 0;
    int m = sum + t >> 1;
    vector<int> f(m + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = m; j >= a[i - 1]; j--)
        f[j] += f[j - a[i - 1]];
    return f[m];
  }
};
// @lc code=end
