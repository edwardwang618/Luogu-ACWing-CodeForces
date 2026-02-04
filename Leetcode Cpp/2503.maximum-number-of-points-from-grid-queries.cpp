/*
 * @lc app=leetcode id=2503 lang=cpp
 *
 * [2503] Maximum Number of Points From Grid Queries
 */

// @lc code=start
class Solution {
public:
  vector<int> maxPoints(vector<vector<int>> &g, vector<int> &qss) {
    int m = g.size(), n = g[0].size();
    int mn = m * n;
    auto id = [&](int x, int y) { return x * n + y; };
    using PII = pair<int, int>;
    vector<PII> cells;
    cells.reserve(mn);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cells.emplace_back(g[i][j], id(i, j));
    sort(cells.begin(), cells.end());
    vector<int> p(mn), sz(mn, 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    auto merge = [&](int x, int y) {
      x = find(x), y = find(y);
      if (x != y) {
        p[x] = y;
        sz[y] += sz[x];
      }
    };

    int q = qss.size();
    vector<PII> qs(q);
    for (int i = 0; i < q; i++)
      qs[i] = {qss[i], i};
    sort(qs.begin(), qs.end());
    vector<bool> used(mn);
    auto add = [&](int idxy) {
      int x = idxy / n, y = idxy % n;
      static constexpr int d[]{1, 0, -1, 0, 1};
      for (int k = 0; k < 4; k++) {
        int nx = x + d[k], ny = y + d[k + 1];
        int nid = id(nx, ny);
        if (0 <= nx && nx < m && 0 <= ny && ny < n && used[nid])
          merge(idxy, nid);
      }
    };

    vector<int> res(q);
    int idx = 0;
    for (auto [th, i] : qs) {
      while (idx < mn && cells[idx].first < th) {
        int pos = cells[idx].second;
        used[pos] = true;
        add(pos);
        idx++;
      }
      if (used[0])
        res[i] = sz[find(0)];
    }
    return res;
  }
};
// @lc code=end
