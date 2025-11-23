/*
 * @lc app=leetcode id=1631 lang=cpp
 *
 * [1631] Path With Minimum Effort
 */

// @lc code=start
class Solution {
 public:
  struct Edge {
    int x, y, w;
  };
  vector<int> p;
  int minimumEffortPath(vector<vector<int>>& hs) {
    int m = hs.size(), n = hs[0].size(), mn = m * n;
    p.resize(mn);
    for (int i = 0; i < mn; i++) p[i] = i;
    vector<Edge> v;
    auto f = [&](int x, int y) { return x * n + y; };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (i + 1 < m)
          v.push_back({f(i + 1, j), f(i, j), abs(hs[i + 1][j] - hs[i][j])});
        if (j + 1 < n)
          v.push_back({f(i, j + 1), f(i, j), abs(hs[i][j + 1] - hs[i][j])});
      }
    sort(v.begin(), v.end(), [&](auto& e1, auto& e2) { return e1.w < e2.w; });
    auto merge = [&](int x, int y) {
      int px = find(p[x]), py = find(y);
      if (px == py) return;
      p[px] = py;
    };
    for (int i = 0; i < v.size(); i++) {
      int x = v[i].x, y = v[i].y, w = v[i].w;
      merge(x, y);
      if (find(f(0, 0)) == find(f(m - 1, n - 1))) return w;
    }

    return 0;
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
};
// @lc code=end
