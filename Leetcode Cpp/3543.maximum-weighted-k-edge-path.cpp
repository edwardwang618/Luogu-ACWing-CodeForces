/*
 * @lc app=leetcode id=3543 lang=cpp
 *
 * [3543] Maximum Weighted K-Edge Path
 */

// @lc code=start
class Solution {
public:
  int maxWeight(int n, vector<vector<int>> &es, int k, int t) {
    int m = es.size();
    vector<int> h(n, -1), e(m), ne(m), w(m);
    int idx = 0;
    auto add = [&](int a, int b, int c) {
      e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
    };
    // vector<int> ind(n);
    for (auto &e : es) {
      add(e[0], e[1], e[2]);
      // ind[e[1]]++;
    }
    static constexpr int T = 600;
    vector f(n, vector<bitset<T>>(k + 1));

    // queue<int> q;
    // for (int i = 0; i < n; i++) {
    //   if (!ind[i]) q.push(i);
    //   f[i][0].set(0);
    // }

    // while (q.size()) {
    //   int u = q.front(); q.pop();
    //   for (int i = h[u]; ~i; i = ne[i]) {
    //     int v = e[i];
    //     for (int j = 1; j <= k; j++)
    //       if (f[u][j - 1].any())
    //         f[v][j] |= f[u][j - 1] << w[i];
    //     if (!--ind[v]) q.push(v);
    //   }
    // }

    vector vis(n, vector<bool>(k + 1, false));

    auto dfs = [&](this auto &&dfs, int u, int cnt) -> bitset<T> & {
      if (vis[u][cnt]) return f[u][cnt];
      vis[u][cnt] = true;

      if (!cnt) {
        f[u][cnt].set(0);
        return f[u][cnt];
      }

      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        f[u][cnt] |= (dfs(v, cnt - 1) << c);
      }
      return f[u][cnt];
    };

    int res = -1;
    for (int i = 0; i < n; i++) {
      dfs(i, k);
      for (int s = t - 1; s >= 0; s--) {
        if (f[i][k][s]) {
          res = max(res, s);
          break;
        }
      }
    }

    // int res = -1;
    // for (int i = 0; i < n; i++) {
    //   for (int s = t - 1; s >= 0; s--) {
    //     if (f[i][k][s]) {
    //       res = max(res, s);
    //       break;
    //     }
    //   }
    // }
    return res;
  }
};
// @lc code=end
