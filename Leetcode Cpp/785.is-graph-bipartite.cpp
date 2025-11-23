/*
 * @lc app=leetcode id=785 lang=cpp
 *
 * [785] Is Graph Bipartite?
 */

// @lc code=start
class Solution {
 public:
  // bool isBipartite(vector<vector<int>>& g) {
  //   int n = g.size();
  //   vector<int> col(n, -1);
  //   for (int i = 0; i < n; i++)
  //     if (!~col[i] && !dfs(i, 0, col, g)) return false;
  //   return true;
  // }

  // bool dfs(int u, int c, auto& col, auto& g) {
  //   col[u] = c;
  //   for (int ne : g[u]) {
  //     if (~col[ne]) {
  //       if (col[ne] == col[u]) return false;
  //     } else if (!dfs(ne, c ^ 1, col, g))
  //       return false;
  //   }

  //   return true;
  // }

  vector<int> p;

  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

  bool isBipartite(vector<vector<int>>& g) {
    int n = g.size();
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;
    for (int i = 0; i < n; i++)
      for (int ne : g[i]) {
        int pne = find(ne);
        if (find(i) == pne) return false;
        p[find(g[i][0])] = pne;
      }
    return true;
  }
};
// @lc code=end
