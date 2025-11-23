/*
 * @lc app=leetcode id=910 lang=cpp
 *
 * [910] Smallest Range II
 */

// @lc code=start
class Solution {
 public:
  int smallestRangeII(vector<int>& a, int k) {
    sort(a.begin(), a.end());
    int res = a.back() - a[0];
    for (int i = 0; i + 1 < a.size(); i++) {
      int M = max(a.back() - k, a[i] + k);
      int m = min(a[0] + k, a[i + 1] - k);
      res = min(res, M - m);
    }
    return res;
  }
};
// @lc code=end
