/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> getSumAbsoluteDifferences(vector<int>& a) {
    int n = a.size();
    int p[n + 1];
    memset(p, 0, sizeof p);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + a[i];
    for (int i = 0; i < n; i++)
      a[i] = (2 * i + 1 - n) * a[i] - p[i] + p[n] - p[i + 1];

    return a;
  }
};
// @lc code=end
