/*
 * @lc app=leetcode id=1828 lang=cpp
 *
 * [1828] Queries on Number of Points Inside a Circle
 */

// @lc code=start
class Solution {
 public:
  vector<int> countPoints(vector<vector<int>>& points,
                          vector<vector<int>>& queries) {
    vector<int> res(queries.size());
    for (int i = 0; i < queries.size(); i++) {
      auto& q = queries[i];
      for (auto& p : points) {
        int dx = p[0] - q[0], dy = p[1] - q[1], r = q[2];
        if (dx * dx + dy * dy <= r * r) res[i]++;
      }
    }

    return res;
  }
};
// @lc code=end
