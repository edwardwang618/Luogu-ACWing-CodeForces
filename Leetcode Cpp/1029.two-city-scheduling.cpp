/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
class Solution {
 public:
  int twoCitySchedCost(vector<vector<int>> &costs) {
    sort(costs.begin(), costs.end(),
         [&](auto &v1, auto &v2) { return v1[0] - v1[1] < v2[0] - v2[1]; });
    int res = 0, n = costs.size();
    for (int i = 0; i < n / 2; i++) res += costs[i][0];
    for (int i = n / 2; i < n; i++) res += costs[i][1];
    return res;
  }
};
// @lc code=end
