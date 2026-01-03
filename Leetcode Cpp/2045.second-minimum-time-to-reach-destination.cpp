/*
 * @lc app=leetcode id=2045 lang=cpp
 *
 * [2045] Second Minimum Time to Reach Destination
 */

// @lc code=start
class Solution {
public:
  int secondMinimum(int n, vector<vector<int>> &es, int time, int change) {
    int m = es.size();
    vector<int> h(n + 1, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }
    constexpr int INF = 2e9;
    vector<int> dist1(n + 1, INF), dist2(n + 1, INF);
    [&]() {
      int step = 0;
      queue<int> q;
      q.push(1);
      dist1[1] = 0;
      while (q.size()) {
        step++;
        for (int _ = q.size(); _; _--) {
          auto u = q.front(); q.pop();
          for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (step < dist1[v]) {
              dist2[v] = dist1[v];
              dist1[v] = step;
              q.push(v);
            } else if (step > dist1[v] && step < dist2[v]) {
              dist2[v] = step;
              if (v == n) return;
              q.push(v);
            }
          }
        }
      }
    }();

    int dist = dist2[n];
    int res = 0;
    for (int i = 0; i < dist; i++) {
      int cycle = res / change;
      if (cycle % 2) res = (cycle + 1) * change;
      res += time;
    }
    return res;
  }
};
// @lc code=end
