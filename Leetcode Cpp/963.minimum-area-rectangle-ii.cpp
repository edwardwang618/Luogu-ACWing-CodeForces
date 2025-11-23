/*
 * @lc app=leetcode id=963 lang=cpp
 *
 * [963] Minimum Area Rectangle II
 */

// @lc code=start
class Solution {
 public:
  long get_dist(vector<int>& a, vector<int>& b) {
    long dx = a[0] - b[0], dy = a[1] - b[1];
    return dx * dx + dy * dy;
  }

  double minAreaFreeRect(vector<vector<int>>& p) {
    int n = p.size();
    vector<vector<long>> v;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++) {
        long x1 = p[i][0], y1 = p[i][1], x2 = p[j][0], y2 = p[j][1];
        long cx = x1 + x2, cy = y1 + y2;
        v.push_back({cx, cy, get_dist(p[i], p[j]), i, j});
      }

    sort(v.begin(), v.end());
    double res = 1e20;
    for (int i = 0; i < v.size(); i++) {
      int j = i + 1;
      while (j < v.size() && v[i][0] == v[j][0] && v[i][1] == v[j][1] &&
             v[i][2] == v[j][2])
        j++;
      for (int a = i; a < j; a++)
        for (int b = i; b < a; b++) {
          auto &a1 = p[v[a][3]], &a2 = p[v[a][4]], &b1 = p[v[b][3]],
               &b2 = p[v[b][4]];
          double area = sqrt(get_dist(a1, b1)) * sqrt(get_dist(a1, b2));
          if (area > 0) res = min(res, area);
        }
      i = j - 1;
    }

    return res == 1e20 ? 0 : res;
  }
};
// @lc code=end
