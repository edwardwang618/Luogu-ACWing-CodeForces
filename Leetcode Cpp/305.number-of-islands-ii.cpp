/*
 * @lc app=leetcode id=305 lang=cpp
 *
 * [305] Number of Islands II
 */

// @lc code=start
class Solution {
 public:
  vector<int> p;
  int cnt;
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    p[px] = py;
    cnt--;
  }

  vector<int> numIslands2(int m, int n, vector<vector<int>>& ps) {
    p.resize(m * n, -1);
    static int d[] = {-1, 0, 1, 0, -1};
    auto f = [&](int x, int y) { return x * n + y; };
    vector<int> res;
    for (auto& po : ps) {
      int x = po[0], y = po[1];
      int u = f(x, y);
      if (!~p[u]) {
        p[u] = u;
        cnt++;
        for (int k = 0; k < 4; k++) {
          int nx = x + d[k], ny = y + d[k + 1];
          int v = f(nx, ny);
          if (0 <= nx && nx < m && 0 <= ny && ny < n && ~p[v]) merge(u, v);
        }
      }
      res.push_back(cnt);
    }

    return res;
  }
};
// @lc code=end
