/*
 * @lc app=leetcode id=2508 lang=cpp
 *
 * [2508] Add Edges to Make Degrees of All Nodes Even
 */

// @lc code=start
class Solution {
 public:
  bool isPossible(int n, vector<vector<int>>& es) {
    unordered_map<int, unordered_set<int>> g;
    for (auto& e : es) {
      g[e[0]].insert(e[1]);
      g[e[1]].insert(e[0]);
    }

    vector<int> vs;
    for (int i = 1; i <= n; i++)
      if (g[i].size() & 1) vs.push_back(i);

    if (vs.empty()) return true;
    if (vs.size() == 2) {
      int u = vs[0], v = vs[1];
      if (!g[u].count(v)) return true;
      for (int w = 1; w <= n; w++)
        if (w != u && w != v && !g[w].count(u) && !g[w].count(v)) return true;
      return false;
    }

    if (vs.size() == 4) {
      for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
          vector<int> a = {vs[i], vs[j]};
          vector<int> b;
          for (int k = 0; k < 4; ++k)
            if (k != i && k != j) b.push_back(vs[k]);

          if (!g[a[0]].count(a[1]) && !g[b[0]].count(b[1])) return true;
        }
      }
    }

    return false;
  }
};
// @lc code=end
