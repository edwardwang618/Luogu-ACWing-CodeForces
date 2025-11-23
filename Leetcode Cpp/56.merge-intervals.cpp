/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& is) {
    sort(is.begin(), is.end());
    vector<vector<int>> res;
    for (auto& p : is) {
      if (res.empty() || p[0] > res.back()[1]) res.push_back(p);
      else res.back()[1] = max(res.back()[1], p[1]);
    }
    return res;
  }
};
// @lc code=end
