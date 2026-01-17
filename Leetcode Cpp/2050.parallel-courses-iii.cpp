/*
 * @lc app=leetcode id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

// @lc code=start
class Solution {
public:
  int minimumTime(int n, vector<vector<int>> &es, vector<int> &time) {
    int m = es.size();
    vector<int> h(n, -1), e(m), ne(m);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    vector<int> ind(n);
    for (auto &e : es) {
      int a = e[0] - 1, b = e[1] - 1;
      add(a, b);
      ind[b]++;
    }

    queue<int> q;
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
      if (!ind[i]) {
        q.push(i);
        dist[i] = time[i];
      }
    
    while (q.size()) {
      auto u = q.front(); q.pop();
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        dist[v] = max(dist[v], time[v] + dist[u]);
        if (!--ind[v]) q.push(v);
      }
    }

    int res = 0;
    for (int x : dist) res = max(res, x);
    return res;
  }
};
// @lc code=end
