/*
 * @lc app=leetcode id=2039 lang=cpp
 *
 * [2039] The Time When the Network Becomes Idle
 */

// @lc code=start
class Solution {
public:
  int networkBecomesIdle(vector<vector<int>> &es, vector<int> &p) {
    int n = p.size(), m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (q.size()) {
      int u = q.front(); q.pop();
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (!~dist[v]) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
      int tot = 2 * dist[i];
      int last_reply = (tot - 1) / p[i] * p[i] + tot + 1;
      res = max(res, last_reply);
    }

    return res;
  }
};
// @lc code=end
