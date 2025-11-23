/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
 public:
  int maxSumTwoNoOverlap(vector<int>& v, int l1, int l2) {
    auto solve = [&](int l1, int l2) {
      int n = v.size(), s[n + 1];
      s[0] = 0;
      for (int i = 0; i < n; i++) s[i + 1] = s[i] + v[i];
      int res = 0;
      for (int i = l1 + l2, max1 = 0; i <= n; i++) {
        max1 = max(max1, s[i - l2] - s[i - l2 - l1]);
        res = max(res, s[i] - s[i - l2] + max1);
      }
      return res;
    };

    return max(solve(l1, l2), solve(l2, l1));
  }
};
// @lc code=end
