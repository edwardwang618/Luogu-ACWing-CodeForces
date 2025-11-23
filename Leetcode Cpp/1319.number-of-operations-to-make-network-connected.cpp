/*
 * @lc app=leetcode id=1319 lang=cpp
 *
 * [1319] Number of Operations to Make Network Connected
 */

// @lc code=start
class Solution {
 public:
  vector<int> p;
  int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
  }

  int makeConnected(int n, vector<vector<int>>& es) {
    if (es.size() < n - 1) return -1;
    p.resize(n);
    for (int i = 0; i < n; i++) p[i] = i;

    for (auto& e : es) {
      int x = e[0], y = e[1];
      int px = find(x), py = find(y);
      if (px != py) {
        p[px] = py;
        n--;
      }
    }

    return n - 1;
  }
};
// @lc code=end
