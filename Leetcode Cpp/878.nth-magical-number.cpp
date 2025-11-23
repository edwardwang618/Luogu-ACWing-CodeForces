/*
 * @lc app=leetcode id=878 lang=cpp
 *
 * [878] Nth Magical Number
 */

// @lc code=start
class Solution {
 public:
  int nthMagicalNumber(int n, int a, int b) {
    const int MOD = 1e9 + 7;
    int g = gcd(a, b);
    auto check = [&](long x) { return x / a + x / b - x / (a * b / g) >= n; };
    long l = 1, r = (long)min(a, b) * n;
    while (l < r) {
      long mid = l + (r - l >> 1l);
      if (check(mid)) r = mid;
      else l = mid + 1;
    }

    return l % MOD;
  }

  int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
};
// @lc code=end
