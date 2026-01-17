/*
 * @lc app=leetcode id=2608 lang=cpp
 *
 * [2608] Shortest Cycle in a Graph
 */

// @lc code=start
class Solution {
public:
  int findShortestCycle(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    constexpr int INF = 2e9;
    int res = INF;
    auto bfs = [&](int u, int v) {
      queue<int> bq, eq;
      bq.push(u), eq.push(v);
      vector<bool> bvis(n), evis(n);
      bvis[u] = evis[v] = true;
      auto one_step = [&](auto &bq, auto &bvis, auto &evis) {
        for (int _ = bq.size(); _--; ) {
          int u = bq.front(); bq.pop();
          for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (bvis[v]) continue;
            if (evis[v]) return true;
            bvis[v] = true;
            bq.push(v);
          }
        }
        return false;
      };
      int step = 0;
      while (bq.size() && eq.size()) {
        step++;
        if (step >= res) return INF;
        if (bq.size() < eq.size()) {
          if (one_step(bq, bvis, evis)) return step;
        } else if (one_step(eq, evis, bvis)) return step;
      }
      return INF;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      int pa = find(a), pb = find(b);
      if (pa == pb) res = min(res, bfs(a, b) + 1);
      else p[pa] = pb;
      add(a, b), add(b, a);
    }

    return res == INF ? -1 : res;
  }
};
// @lc code=end
