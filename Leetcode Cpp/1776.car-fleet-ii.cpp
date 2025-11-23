/*
 * @lc app=leetcode id=1776 lang=cpp
 *
 * [1776] Car Fleet II
 */

// @lc code=start
class Solution {
 public:
  using PDD = pair<double, double>;
#define x first
#define y second

#define cross(x1, y1, x2, y2) ((x1) * (y2) - (x2) * (y1))

  double area(PDD &a, PDD &b, PDD &c) {
    return cross(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
  }

  vector<double> getCollisionTimes(vector<vector<int>> &v) {
    int n = v.size();
    vector<PDD> stk;
    vector<double> res(n);
    for (int i = n - 1; i >= 0; i--) {
      auto &c = v[i];
      PDD p(c[0], c[1]);
      while (stk.size() >= 2 && area(p, stk[stk.size() - 2], stk.back()) >= 0)
        stk.pop_back();
      if (stk.empty()) res[i] = -1;
      else {
        auto &q = stk.back();
        if (p.y <= q.y) res[i] = -1;
        else res[i] = (q.x - p.x) / (p.y - q.y);
      }

      stk.push_back(p);
    }

    return res;
  }
};
// @lc code=end
