/*
 * @lc app=leetcode id=3807 lang=cpp
 *
 * [3807] Minimum Cost to Repair Edges to Traverse a Graph
 */

// @lc code=start
class Solution {
public:
  int minCost(int n, vector<vector<int>> &es, int k) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1), w(m << 1);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    vector<int> lens;
    lens.reserve(m);
    for (auto &e : es) {
      int a = e[0], b = e[1], c = e[2];
      add(a, b, c), add(b, a, c);
      lens.push_back(c);
    }
    sort(lens.begin(), lens.end());
    lens.erase(unique(lens.begin(), lens.end()), lens.end());
    auto bfs = [&](int maxLen) {
      assert(n >= 2);
      queue<int> q{{0}};
      vector<bool> vis(n);
      vis[0] = true;
      int step = 0;
      while (q.size()) {
        step++;
        if (step > k) return false;
        for (int _ = q.size(); _--; ) {
          int u = q.front(); q.pop();
          for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i], c = w[i];
            if (c <= maxLen && !vis[v]) {
              if (v == n - 1) return true;
              vis[v] = true;
              q.push(v);
            }
          }
        }
      }
      return false;
    };
    int l = 0, r = lens.size() - 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (bfs(lens[mid])) r = mid;
      else l = mid + 1;
    }
    return bfs(lens[l]) ? lens[l] : -1;
  }
};
// @lc code=end
