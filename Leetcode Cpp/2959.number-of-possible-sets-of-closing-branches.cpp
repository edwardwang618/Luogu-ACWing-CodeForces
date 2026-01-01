/*
 * @lc app=leetcode id=2959 lang=cpp
 *
 * [2959] Number of Possible Sets of Closing Branches
 */

// @lc code=start
class Solution {
public:
  int numberOfSets(int n, int maxd, vector<vector<int>> &es) {
    int res = 0;
    for (int s = 0; s < (1 << n); s++) {
      vector<int> open;
      for (int i = 0; i < n; i++)
        if (s >> i & 1)
          open.push_back(i);
      int m = open.size();
      if (m <= 1) {
        res++;
        continue;
      }
      vector<int> id(n, -1);
      for (int i = 0; i < m; i++)
        id[open[i]] = i;
      constexpr int INF = 2e9;
      vector<vector<int>> dist(m, vector<int>(m, INF));
      for (int i = 0; i < m; i++)
        dist[i][i] = 0;
      for (auto &e : es) {
        int u = e[0], v = e[1], w = e[2];
        if (int a = id[u], b = id[v]; ~a && ~b)
          dist[a][b] = dist[b][a] = min(dist[a][b], w);
      }
      for (int k = 0; k < m; k++)
        for (int i = 0; i < m; i++)
          for (int j = 0; j < m; j++)
            if (dist[i][k] != INF && dist[k][j] != INF)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

      if ([&]() {
            for (int i = 0; i < m; i++)
              for (int j = i + 1; j < m; j++)
                if (dist[i][j] > maxd)
                  return false;
            return true;
          }())
        res++;
    }
    return res;
  }
};
// @lc code=end
