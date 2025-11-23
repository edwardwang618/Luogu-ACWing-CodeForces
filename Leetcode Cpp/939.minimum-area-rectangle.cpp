/*
 * @lc app=leetcode id=939 lang=cpp
 *
 * [939] Minimum Area Rectangle
 */

// @lc code=start
class Solution {
 public:
  struct Point {
    int x, y;
    bool operator==(const Point& p) const { return x == p.x && y == p.y; }
  };
  int minAreaRect(vector<vector<int>>& ps) {
    auto phash = [](const Point& p) {
      return hash<int>()(p.x) ^ hash<int>()(p.y);
    };
    unordered_set<Point, decltype(phash)> S(0, phash);
    for (auto& p : ps) S.insert({p[0], p[1]});
    int res = 2e9;
    for (int i = 0; i < ps.size(); i++)
      for (int j = i + 1; j < ps.size(); j++) {
        int x1 = ps[i][0], y1 = ps[i][1];
        int x2 = ps[j][0], y2 = ps[j][1];
        if (x1 == x2 || y1 == y2) continue;
        if (S.count({x1, y2}) && S.count({x2, y1}))
          res = min(res, abs((x1 - x2) * (y1 - y2)));
      }

    return res == (int)2e9 ? 0 : res;
  }
};
// @lc code=end
