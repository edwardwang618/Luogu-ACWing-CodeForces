/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
 public:
  int numSubarrayProductLessThanK(vector<int>& a, int k) {
    int res = 0;
    for (int i = 0, j = 0, prod = 1; i < a.size(); i++) {
      prod *= a[i];
      while (j <= i && prod >= k) prod /= a[j++];
      res += i - j + 1;
    }
    return res;
  }
};
// @lc code=end
