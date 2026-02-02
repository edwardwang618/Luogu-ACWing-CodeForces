/*
 * @lc app=leetcode id=1743 lang=cpp
 *
 * [1743] Restore the Array From Adjacent Pairs
 */

// @lc code=start
class Solution {
public:
  vector<int> restoreArray(vector<vector<int>> &ps) {
    unordered_map<int, vector<int>> g;
    for (auto &p : ps) {
      int x = p[0], y = p[1];
      g[x].push_back(y);
      g[y].push_back(x);
    }

    int st = -2e9;
    for (auto &[k, v] : g)
      if (v.size() == 1) {
        st = k;
        break;
      }

    int n = ps.size() + 1;
    vector<int> res;
    res.reserve(n);

    int prev = -2e9, cur = st;
    while (res.size() < n) {
      res.push_back(cur);
      auto it = g.find(cur);
      assert(it != g.end());
      for (int ne : it->second)
        if (ne != prev) {
          prev = cur;
          cur = ne;
          break;
        }
    }
    return res;
  }
};
// @lc code=end
