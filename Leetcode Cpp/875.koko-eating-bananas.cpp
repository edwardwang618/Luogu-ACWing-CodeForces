/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
 public:
  int minEatingSpeed(vector<int>& v, int h) {
    int l = 1, r = 0;
    for (int x : v) r = max(r, x);
    auto check = [&](int s) {
      int t = 0;
      for (int x : v) t += (x + s - 1) / s;
      return t <= h;
    };
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (check(mid)) r = mid;
      else l = mid + 1;
    }

    return l;
  }
};
// @lc code=end
