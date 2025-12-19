/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
class Solution {
public:
  int largestPathValue(string &col, vector<vector<int>> &es) {
    int n = col.size(), m = es.size();
    vector<int> h(n, -1), e(m), ne(m), ind(n);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (auto &e : es) {
      add(e[0], e[1]);
      ind[e[1]]++;
    }
    vector<array<int, 26>> cnt(n, array<int, 26>{});

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (!ind[i])
        q.push(i);

    int res = 0, vis_cnt = 0;
    while (q.size()) {
      int u = q.front();
      q.pop();
      vis_cnt++;
      int cu = col[u] - 'a';
      cnt[u][cu]++;
      res = max(res, cnt[u][cu]);
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], cv = col[v] - 'a';
        for (int c = 0; c < 26; c++)
          cnt[v][c] = max(cnt[v][c], cnt[u][c]);
        if (!--ind[v])
          q.push(v);
      }
    }

    return vis_cnt == n ? res : -1;
  }
};
// @lc code=end
