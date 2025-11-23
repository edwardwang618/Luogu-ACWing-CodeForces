/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
 public:
  int minSubArrayLen(int t, vector<int>& A) {
    int n = A.size(), res = n + 1;
    for (int i = 0, j = 0, sum = 0; i < n; i++) {
      sum += A[i];
      while (j < i && sum - A[j] >= t) sum -= A[j++];
      if (sum >= t) res = min(res, i - j + 1);
    }
    return res == n + 1 ? 0 : res;
  }
};
// @lc code=end
