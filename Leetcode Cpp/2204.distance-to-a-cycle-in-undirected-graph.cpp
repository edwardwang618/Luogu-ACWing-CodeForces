/*
 * @lc app=leetcode id=2204 lang=cpp
 *
 * [2204] Distance to a Cycle in Undirected Graph
 */

// @lc code=start
class Solution {
public:
  vector<int> distanceToCycle(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), ind(n);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
      ind[a]++, ind[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) if (ind[i] == 1) q.push(i);
    vector<bool> on_cycle(n, true);
    while (q.size()) {
      int u = q.front(); q.pop();
      on_cycle[u] = false;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (--ind[v] == 1) q.push(v);
      }
    }

    vector<int> res(n, -1);
    for (int i = 0; i < n; i++)
      if (on_cycle[i]) {
        res[i] = 0;
        q.push(i);
      }

    int step = 0;
    while (q.size()) {
      step++;
      for (int i = q.size(); i; i--) {
        int u = q.front(); q.pop();
        for (int j = h[u]; ~j; j = ne[j]) {
          int v = e[j];
          if (!~res[v]) {
            res[v] = step;
            q.push(v);
          }
        }
      }
    }

    return res;
  }
};
// @lc code=end
