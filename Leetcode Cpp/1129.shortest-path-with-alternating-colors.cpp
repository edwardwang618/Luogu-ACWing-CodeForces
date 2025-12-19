/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
public:
using PII = pair<int, int>;
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &re,
                                       vector<vector<int>> &be) {
    int m = re.size() + be.size(), idx = 0;
    vector<int> h(n, -1), e(m, 0), ne(m, 0), col(m, -1);
    auto add = [&](int a, int b, int c) {
      e[idx] = b;
      ne[idx] = h[a];
      col[idx] = c;
      h[a] = idx++;
    };
    for (auto &e : re) add(e[0], e[1], 0);
    for (auto &e : be) add(e[0], e[1], 1);
    queue<PII> q;
    q.push({0, -1});
    vector<vector<int>> dist(2, vector<int>(n, -1));
    dist[0][0] = dist[1][0] = 0;
    while (q.size()) {
      for (int i = q.size(); i; i--) {
        auto [u, c] = q.front(); q.pop();
        for (int j = h[u]; ~j; j = ne[j]) {
          int v = e[j], nc = col[j];
          if (c ^ nc && !~dist[nc][v]) {
            if (!~c) dist[nc][v] = 1;
            else dist[nc][v] = dist[c][u] + 1;
            q.push({v, nc});
          }
        }
      }
    }
    vector<int> res;
    res.reserve(n);
    for (int i = 0; i < n; i++)
      if (~dist[0][i] && ~dist[1][i]) res.push_back(min(dist[0][i], dist[1][i]));
      else res.push_back(dist[0][i] & dist[1][i]);
    return res;
  }
};
// @lc code=end
