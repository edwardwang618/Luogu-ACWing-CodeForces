/*
 * @lc app=leetcode id=3787 lang=cpp
 *
 * [3787] Find Diameter Endpoints of a Tree
 */

// @lc code=start
class Solution {
public:
  string findSpecialNodes(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
    }
    vector<int> dist_a(n), dist_b(n);
    auto dfs = [&](this auto &&dfs, int u, int from, auto &dist) -> void {
      if (~from)
        dist[u] = dist[from] + 1;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v != from)
          dfs(v, u, dist);
      }
    };
    dist_a[0] = 0;
    dfs(0, -1, dist_a);
    int a = max_element(dist_a.begin(), dist_a.end()) - dist_a.begin();
    dist_a[a] = 0;
    dfs(a, -1, dist_a);
    int b = max_element(dist_a.begin(), dist_a.end()) - dist_a.begin();
    int dia = dist_a[b];
    dfs(b, -1, dist_b);

    string res(n, '0');
    for (int i = 0; i < n; i++)
      if (dist_a[i] == dia || dist_b[i] == dia)
        res[i] = '1';
    return res;
  }
};
// @lc code=end
