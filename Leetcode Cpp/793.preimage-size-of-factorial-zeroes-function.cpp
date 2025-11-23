/*
 * @lc app=leetcode id=793 lang=cpp
 *
 * [793] Preimage Size of Factorial Zeroes Function
 */

// @lc code=start
class Solution {
 public:
  int preimageSizeFZF(int k) {
    if (!k) return 5;
    auto f = [](long x) {
      long res = 0;
      while (x) res += x / 5, x /= 5;
      return res;
    };
    auto calc = [&f](long k) {
      long l = k, r = 5 * (k + 1);
      while (l < r) {
        long mid = l + (r - l + 1 >> 1);
        if (f(mid) <= k) l = mid;
        else r = mid - 1;
      }
      return l;
    };
    return calc(k) - calc(k - 1);
  }
};
// @lc code=end
