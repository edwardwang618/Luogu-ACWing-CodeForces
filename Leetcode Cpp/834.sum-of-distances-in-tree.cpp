/*
 * @lc app=leetcode id=834 lang=cpp
 *
 * [834] Sum of Distances in Tree
 */

// @lc code=start
class Solution {
public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &es) {
    int m = es.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };

    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b);
      add(b, a);
    }

    vector<int> res(n), cnt(n);
    auto dfs1 = [&](auto&& self, int u, int from, int dist) -> int {
      cnt[u] = 1;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == from) continue;
        res[0] += dist + 1;
        cnt[u] += self(self, v, u, dist + 1);
      }
      return cnt[u];
    };
    dfs1(dfs1, 0, -1, 0);
    
    auto dfs2 = [&](auto&& self, int u, int from) -> void {
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (v == from) continue;
        res[v] = res[u] + (n - cnt[v]) - cnt[v];
        self(self, v, u);
      }
    };
    dfs2(dfs2, 0, -1);
    return res;
  }
};
// @lc code=end
