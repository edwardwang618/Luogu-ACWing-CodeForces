/*
 * @lc app=leetcode id=2771 lang=cpp
 *
 * [2771] Longest Non-decreasing Subarray From Two Arrays
 */

// @lc code=start
class Solution {
 public:
  int maxNonDecreasingLength(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int f[n][2];
    memset(f, 0, sizeof f);
    f[0][0] = f[0][1] = 1;
    int res = 1;
    for (int i = 1; i < n; i++) {
      f[i][0] = f[i][1] = 1;
      if (a[i] >= a[i - 1]) f[i][0] = max(f[i][0], f[i - 1][0] + 1);
      if (a[i] >= b[i - 1]) f[i][0] = max(f[i][0], f[i - 1][1] + 1);
      if (b[i] >= b[i - 1]) f[i][1] = max(f[i][1], f[i - 1][1] + 1);
      if (b[i] >= a[i - 1]) f[i][1] = max(f[i][1], f[i - 1][0] + 1);
      res = max(res, max(f[i][0], f[i][1]));
    }

    return res;
  }
};
// @lc code=end
