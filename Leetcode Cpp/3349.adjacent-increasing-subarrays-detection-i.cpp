/*
 * @lc app=leetcode id=3349 lang=cpp
 *
 * [3349] Adjacent Increasing Subarrays Detection I
 */

// @lc code=start
class Solution {
 public:
  bool hasIncreasingSubarrays(vector<int>& a, int k) {
    for (int i = 0; i + 2 * k <= a.size(); i++) {
      int j;
      for (j = i + 1; j < i + k; j++)
        if (a[j] <= a[j - 1]) {
          i = j - 1;
          break;
        }

      if (j != i + k) continue;
      for (j++; j < i + 2 * k; j++)
        if (a[j] <= a[j - 1]) {
          i = j - k - 1;
          break;
        }

      if (j == i + 2 * k) return true;
    }
    return false;
  }
};
// @lc code=end
