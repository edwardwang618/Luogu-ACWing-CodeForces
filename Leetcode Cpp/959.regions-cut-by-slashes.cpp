/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
class Solution {
 public:
  int n, res;
  vector<int> p;
  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }
  void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px != py) {
      p[px] = py;
      res--;
    }
  }
  int regionsBySlashes(vector<string>& g) {
    int n = g.size();
    res = 4 * n * n;
    p.resize(res);
    for (int i = 0; i < res; i++) p[i] = i;
    auto get = [&](int i, int j) { return (i * n + j) * 4; };
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        int a[4] = {get(i, j)};
        for (int k = 1; k < 4; k++) a[k] = a[0] + k;
        char ch = g[i][j];
        if (ch == ' ')
          for (int k = 1; k < 4; k++) merge(a[0], a[k]);
        else if (ch == '/')
          merge(a[0], a[1]), merge(a[2], a[3]);
        else if (ch == '\\')
          merge(a[1], a[2]), merge(a[0], a[3]);
        if (j < n - 1) merge(a[2], a[2] + 2);
        if (i < n - 1) merge(a[3], get(i + 1, j) + 1);
      }

    return res;
  }
};
// @lc code=end
