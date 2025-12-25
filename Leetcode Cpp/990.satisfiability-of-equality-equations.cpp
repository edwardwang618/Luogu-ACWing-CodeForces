/*
 * @lc app=leetcode id=990 lang=cpp
 *
 * [990] Satisfiability of Equality Equations
 */

// @lc code=start
class Solution {
public:
  bool equationsPossible(vector<string> &es) {
    vector<int> p(26);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };

    for (auto &e : es)
      if (e[1] == '=') {
        int px = find(e[0] - 'a'), py = find(e[3] - 'a');
        p[px] = py;
      }

    for (auto &e : es)
      if (e[1] == '!') {
        int px = find(e[0] - 'a'), py = find(e[3] - 'a');
        if (px == py)
          return false;
      }
    return true;
  }
};
// @lc code=end
