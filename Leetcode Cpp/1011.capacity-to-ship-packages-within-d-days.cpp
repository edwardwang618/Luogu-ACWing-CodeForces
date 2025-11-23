/*
 * @lc app=leetcode id=1011 lang=cpp
 *
 * [1011] Capacity To Ship Packages Within D Days
 */

// @lc code=start
class Solution {
 public:
  int shipWithinDays(vector<int>& ws, int days) {
    int l = 0, r = 0;
    for (int x : ws) r += x, l = max(l, x);
    auto f = [&](int cap) {
      int days = 1, cur = 0;
      for (int x : ws) {
        if (cur + x > cap) {
          cur = 0;
          days++;
        }
        cur += x;
      }

      return days;
    };
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (f(mid) <= days) r = mid;
      else l = mid + 1;
    }
    return l;
  }
};
// @lc code=end
