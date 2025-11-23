/*
 * @lc app=leetcode id=1477 lang=cpp
 *
 * [1477] Find Two Non-overlapping Sub-arrays Each With Target Sum
 */

// @lc code=start
class Solution {
 public:
  int minSumOfLengths(vector<int>& v, int target) {
    int n = v.size(), f[n];
    fill(f, f + n, n);
    int res = n + 1;
    for (int i = 0, j = 0, sum = 0; i < n; i++) {
      sum += v[i];
      while (sum - v[j] >= target) sum -= v[j++];
      if (sum == target && j && f[j - 1] < n) res = min(res, i - j + 1 + f[j - 1]);
      if (sum == target) f[i] = i - j + 1;
      if (i) f[i] = min(f[i], f[i - 1]);
    }

    return res <= n ? res : -1;
  }
};
// @lc code=end
