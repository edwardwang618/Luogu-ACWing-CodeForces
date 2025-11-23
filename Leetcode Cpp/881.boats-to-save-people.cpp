/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 */

// @lc code=start
class Solution {
 public:
  int numRescueBoats(vector<int>& p, int t) {
    int res = 0;
    sort(p.begin(), p.end());
    for (int l = 0, r = p.size() - 1; l <= r; r--) {
      if (l < r && p[l] + p[r] <= t) l++;
      res++;
    }

    return res;
  }
};
// @lc code=end
