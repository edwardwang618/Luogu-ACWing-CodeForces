/*
 * @lc app=leetcode id=2603 lang=cpp
 *
 * [2603] Collect Coins in a Tree
 */

// @lc code=start
class Solution {
public:
  int collectTheCoins(vector<int> &coins, vector<vector<int>> &es) {
    int m = es.size(), n = coins.size();
    vector<int> h(n, -1), e(m << 1), ne(m << 1);
    int idx = 0;
    auto add = [&](int a, int b) {
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    };
    vector<int> ind(n);
    for (auto &e : es) {
      int a = e[0], b = e[1];
      add(a, b), add(b, a);
      ind[a]++, ind[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) 
      if (ind[i] == 1 && !coins[i]) {
        ind[i] = 0;
        q.push(i);
      }
    while (q.size()) {
      auto u = q.front(); q.pop();
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (ind[v] && --ind[v] == 1 && !coins[v]) {
          q.push(v);
          ind[v] = 0;
        }
      }
    }

    for (int _ = 0; _ < 2; _++) {
      for (int i = 0; i < n; i++)
        if (ind[i] == 1) {
          q.push(i);
          ind[i] = 0;
        }

      for (int i = q.size(); i; i--) {
        auto u = q.front(); q.pop();
        for (int j = h[u]; ~j; j = ne[j]) {
          int v = e[j];
          if (ind[v]) ind[v]--;
        }
      }
    }

    int res = 0;
    for (auto &e : es)
      if (ind[e[0]] && ind[e[1]]) res += 2;
    return res;
  }
};
// @lc code=end
