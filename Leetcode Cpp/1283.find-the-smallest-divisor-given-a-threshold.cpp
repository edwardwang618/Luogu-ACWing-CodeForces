/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
 public:
  int smallestDivisor(vector<int>& a, int threshold) {
    int l = 1, r = 0;
    for (int x : a) r = max(r, x);
    while (l < r) {
      int mid = l + (r - l >> 1);
      int sum = 0;
      for (int x : a) sum += (x + mid - 1) / mid;
      if (sum <= threshold) r = mid;
      else l = mid + 1;
    }

    return l;
  }
};
// @lc code=end
