/*
 * @lc app=leetcode id=3350 lang=cpp
 *
 * [3350] Adjacent Increasing Subarrays Detection II
 */

// @lc code=start
class Solution {
 public:
  int maxIncreasingSubarrays(vector<int>& a) {
    int n = a.size();
    vector<int> l(n), r(n);
    l[0] = r[n - 1] = 1;

    for (int i = 1; i < n; i++)
      if (a[i - 1] < a[i])
        l[i] = l[i - 1] + 1;
      else
        l[i] = 1;

    for (int i = n - 2; i >= 0; i--)
      if (a[i] < a[i + 1])
        r[i] = r[i + 1] + 1;
      else
        r[i] = 1;

    int res = 0;
    for (int i = 0; i + 1 < n; i++) res = max(res, min(l[i], r[i + 1]));
    return res;
  }
};
// @lc code=end
