/*
 * @lc app=leetcode id=3244 lang=cpp
 *
 * [3244] Shortest Distance After Road Addition Queries II
 */

// @lc code=start
class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &qs) {
    vector<int> ne(n);
    iota(ne.begin(), ne.end(), 1);
    vector<int> res;
    res.reserve(qs.size());
    for (auto &q : qs) {
      int u = q[0], v = q[1];
      if (!~ne[u]) {
        res.push_back(n - 1);
        continue;
      }
      int x = ne[u];
      while (~x && x < v) {
        int y = ne[x];
        ne[x] = -1;
        n--;
        x = y;
      }
      ne[u] = v;
      res.push_back(n - 1);
    }
    return res;
  }
};
// @lc code=end
