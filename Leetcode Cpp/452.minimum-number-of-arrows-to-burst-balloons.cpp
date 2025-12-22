/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
#include <limits>
class Solution {
public:
  using ll = long long;
  int findMinArrowShots(vector<vector<int>> &ps) {
    sort(ps.begin(), ps.end(),
         [&](auto &p1, auto &p2) { return p1[1] < p2[1]; });
    ll cur_end = std::numeric_limits<ll>().min();
    int res = 0;
    for (auto &p : ps)
      if (p[0] > cur_end) {
        cur_end = p[1];
        res++;
      }
    return res;
  }
};
// @lc code=end
