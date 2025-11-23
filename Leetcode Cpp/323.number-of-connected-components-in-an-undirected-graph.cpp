/*
 * @lc app=leetcode id=323 lang=cpp
 *
 * [323] Number of Connected Components in an Undirected Graph
 */

// @lc code=start
class Solution {
 public:
  vector<int> p;
  int countComponents(int n, vector<vector<int>>& edges) {
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;
    int res = n;
    auto merge = [&](int x, int y) {
      int px = find(x), py = find(y);
      if (px != py) p[px] = py, res--;
    };
    for (auto& e : edges) merge(e[0], e[1]);
    return res;
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
};
// @lc code=end
