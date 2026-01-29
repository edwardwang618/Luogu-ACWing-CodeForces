/*
 * @lc app=leetcode id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m), ne(m);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    vector<int> ind(n);
    for (auto &e : es) {
      add(e[0], e[1]);
      ind[e[1]]++;
    }

    queue<int> q;
    static constexpr int N = 1000;
    vector<bitset<N>> anc(n);
    for (int i = 0; i < n; i++) 
      if (!ind[i]) q.push(i);

    while (q.size()) {
      int u = q.front(); q.pop();
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        anc[v] |= anc[u];
        anc[v].set(u);
        if (!--ind[v]) q.push(v);
      }
    }

    vector<vector<int>> res(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (anc[i][j]) res[i].push_back(j);
    return res;
  }
};
// @lc code=end
