/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& ps) {
    int n = ps.size();
    auto calc = [&](vector<int>& a, vector<int>& b, vector<int>& c) {
      int x1 = b[0] - a[0], y1 = b[1] - a[1];
      int x2 = c[0] - a[0], y2 = c[1] - a[1];
      return x1 * y2 - x2 * y1;
    };
    double res = 0;
    for (int i = 0; i + 2 < n; i++)
      for (int j = i + 1; j + 1 < n; j++)
        for (int k = j + 1; k < n; k++)
          res = max(res, (double)abs(calc(ps[i], ps[j], ps[k])));

    return res / 2.0;
  }
};
// @lc code=end
