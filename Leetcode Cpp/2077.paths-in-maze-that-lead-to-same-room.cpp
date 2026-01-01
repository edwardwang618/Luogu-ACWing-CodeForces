/*
 * @lc app=leetcode id=2077 lang=cpp
 *
 * [2077] Paths in Maze That Lead to Same Room
 */

// @lc code=start
class Solution {
public:
  int numberOfPaths(int n, vector<vector<int>> &es) {
    vector<unordered_set<int>> g(n + 1);
    for (auto &e : es) {
      int a = e[0], b = e[1];
      g[a].insert(b);
      g[b].insert(a);
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
      for (int j : g[i]) {
        if (j <= i) continue;
        for (int k : g[j]) {
          if (k <= j) continue;
          if (g[k].count(i)) res++;
        }
      }
    return res;
  }
};
// @lc code=end
