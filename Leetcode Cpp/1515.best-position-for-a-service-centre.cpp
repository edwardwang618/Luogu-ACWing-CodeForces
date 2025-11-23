/*
 * @lc app=leetcode id=1515 lang=cpp
 *
 * [1515] Best Position for a Service Centre
 */

// @lc code=start
class Solution {
 public:
  double getMinDistSum(vector<vector<int>>& ps) {
    constexpr double eps = 1e-8;
    double l = 0, r = 100.0;
    auto get_sum = [&](double x, double y) {
      double sum = 0.0;
      for (auto& p : ps) {
        double a = p[0], b = p[1];
        sum += sqrt((x - a) * (x - a) + (y - b) * (y - b));
      }
      return sum;
    };
    auto calc = [&](double x) -> double {
      double l = 0, r = 100;
      while (r - l > eps) {
        double y1 = l + (r - l) / 3, y2 = l + (r - l) / 3 * 2;
        if (get_sum(x, y1) >= get_sum(x, y2))
          l = y1;
        else
          r = y2;
      }
      return get_sum(x, l);
    };
    while (r - l > eps) {
      double x1 = l + (r - l) / 3, x2 = l + (r - l) / 3 * 2;
      if (calc(x1) > calc(x2))
        l = x1;
      else
        r = x2;
    }
    return calc(l);
  }
};
// @lc code=end
