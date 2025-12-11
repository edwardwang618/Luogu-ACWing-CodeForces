/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
public:
  bool validPath(int n, vector<vector<int>> &es, int sr, int de) {
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](auto &&self, int x) -> int {
      return p[x] == x ? x : p[x] = self(self, p[x]);
    };
    for (auto &e : es) {
      int x = e[0], y = e[1];
      int px = find(find, x), py = find(find, y);
      p[px] = py;
    }
    return find(find, sr) == find(find, de);
  }
};
// @lc code=end
