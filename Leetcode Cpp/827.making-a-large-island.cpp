/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  vector<int> p, sz;
  int largestIsland(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size(), mn = m * n;
    p.resize(mn);
    sz.resize(mn);
    for (int i = 0; i < mn; i++) p[i] = i, sz[i] = 1;
    auto f = [&](int x, int y) { return x * n + y; };
    auto merge = [&](int x, int y) {
      int px = find(x), py = find(y);
      if (px == py) return;
      p[px] = py, sz[py] += sz[px];
    };
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        if (!g[i][j]) continue;
        int x = f(i, j);
        for (auto& pp :
             vector<PII>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
          auto& [nx, ny] = pp;
          if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] == 1)
            merge(x, f(nx, ny));
        }
      }

    int res = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        int x = f(i, j);
        if (g[i][j]) {
          res = max(res, sz[x]);
          continue;
        }
        mp.clear();
        for (auto& pp :
             vector<PII>{{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}}) {
          auto& [nx, ny] = pp;
          if (0 <= nx && nx < m && 0 <= ny && ny < n && g[nx][ny] == 1) {
            int pa = find(f(nx, ny));
            mp[pa] = sz[pa];
          }
        }

        int cnt = 1;
        for (auto& [k, v] : mp) cnt += v;
        res = max(res, cnt);
      }

    return res;
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
};
// @lc code=end
