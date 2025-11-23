/*
 * @lc app=leetcode id=849 lang=cpp
 *
 * [849] Maximize Distance to Closest Person
 */

// @lc code=start
class Solution {
 public:
  int maxDistToClosest(vector<int>& v) {
    int res = 0, last = -1, n = v.size();
    for (int i = 0; i < n; i++)
      if (v[i] == 1) {
        if (!~last) res = i;
        else res = max(res, (i - last) / 2);
        last = i;
      }

    res = max(res, n - 1 - last);
    return res;
  }
};
// @lc code=end
