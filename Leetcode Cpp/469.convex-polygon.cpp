/*
 * @lc app=leetcode id=469 lang=cpp
 *
 * [469] Convex Polygon
 */

// @lc code=start
class Solution {
 public:
  bool isConvex(vector<vector<int>>& ps) {
    int n = ps.size();
    ps.push_back(ps[0]);
    ps.push_back(ps[1]);
    int p = cross(ps[0], ps[1], ps[1], ps[2]) > 0 ? 1 : -1;
    for (int i = 0; i < n; i++)
      if (cross(ps[i], ps[i + 1], ps[i + 1], ps[i + 2]) * p < 0) return false;
    return true;
  }

  int cross(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
    int x1 = b[0] - a[0], x2 = d[0] - c[0];
    int y1 = b[1] - a[1], y2 = d[1] - c[1];
    return x1 * y2 - x2 * y1;
  }
};
// @lc code=end
