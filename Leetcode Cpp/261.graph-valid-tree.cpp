/*
 * @lc app=leetcode id=261 lang=cpp
 *
 * [261] Graph Valid Tree
 */

// @lc code=start
class Solution {
public:
  bool validTree(int n, vector<vector<int>> &es) {
    if (n - 1 != es.size()) return false;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    for (auto &e : es) {
      int a = e[0], b = e[1];
      int pa = find(a), pb = find(b);
      if (pa == pb) return false;
      p[pa] = pb;
    }
    return true;
  }
};
// @lc code=end
