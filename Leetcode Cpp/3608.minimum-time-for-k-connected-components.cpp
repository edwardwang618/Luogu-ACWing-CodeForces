/*
 * @lc app=leetcode id=3608 lang=cpp
 *
 * [3608] Minimum Time for K Connected Components
 */

// @lc code=start
class Solution {
public:
  int minTime(int n, vector<vector<int>> &es, int k) {
    int m = es.size();
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    int cnt = n;
    auto merge = [&](int x, int y) {
      x = find(x), y = find(y);
      if (x != y) {
        p[x] = y;
        cnt--;
      }
    };
    sort(es.begin(), es.end(), [&](auto &e1, auto &e2) {
      return e1[2] > e2[2];
    });
    for (int i = 0; i < m; i++) {
      auto &e = es[i];
      merge(e[0], e[1]);
      if (cnt < k) return e[2];
    }
    return 0;
  }
};
// @lc code=end
