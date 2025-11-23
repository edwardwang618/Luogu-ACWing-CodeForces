/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
 public:
  double myPow(double x, int m) {
    double res = 1.0;
    long long n = m;
    if (n < 0) x = 1.0 / x;
    n = abs(n);
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
    }
    return res;
  }
};
// @lc code=end
