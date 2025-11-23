/*
 * @lc app=leetcode id=478 lang=cpp
 *
 * [478] Generate Random Point in a Circle
 */

// @lc code=start
class Solution {
 public:
  double r, xc, yc, x, y;

  Solution(double radius, double x_center, double y_center) {
    r = radius;
    xc = x_center;
    yc = y_center;
  }

  // vector<double> randPoint() {
  //   double x, y;
  //   do {
  //     x = (double)rand() / RAND_MAX * 2 - 1;
  //     y = (double)rand() / RAND_MAX * 2 - 1;
  //   } while (x * x + y * y > 1);
  //   return {xc + x * r, yc + y * r};
  // }

  vector<double> randPoint() {
    double radius = sqrt((double)rand() / RAND_MAX) * r;
    double theta = ((double)rand() / RAND_MAX) * 2 * acos(-1);
    return {xc + radius * cos(theta), yc + radius * sin(theta)};
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
// @lc code=end
