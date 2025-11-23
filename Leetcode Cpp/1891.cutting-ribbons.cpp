/*
 * @lc app=leetcode id=1891 lang=cpp
 *
 * [1891] Cutting Ribbons
 */

// @lc code=start
class Solution {
 public:
  int maxLength(vector<int>& rs, int k) {
    int l = 1, r = 0;
    for (int x : rs) r = max(r, x);
    auto f = [&](int x) {
      int cnt = 0;
      for (int r : rs) cnt += r / x;
      return cnt >= k;
    };
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (f(mid)) l = mid;
      else r = mid - 1;
    }

    return f(l) ? l : 0;
  }
};
// @lc code=end
