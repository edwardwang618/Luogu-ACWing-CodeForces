/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 */

// @lc code=start
class Solution {
public:
  double new21Game(int n, int k, int maxPts) {
    if (!k || k - 1 + maxPts < n) return 1.0;
    vector<double> f(n + 1);
    f[0] = 1.0;
    double sum = 1.0;
    double res = 0.0;
    for (int i = 1; i <= n; i++) {
      if (i >= 1 + maxPts) sum -= f[i - 1 - maxPts];
      f[i] = sum / maxPts;
      if (i >= k) res += f[i];
      else sum += f[i];
    }
    return res;
  }
};
// @lc code=end
