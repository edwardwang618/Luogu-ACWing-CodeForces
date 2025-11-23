/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& a) {
    int n = a.size(), f;
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (i && a[i] > a[i - 1]) f++;
      else f = 1;
      res = max(res, f);
    }

    return res;
  }
};
// @lc code=end
