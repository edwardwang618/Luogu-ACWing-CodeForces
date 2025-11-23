/*
 * @lc app=leetcode id=498 lang=cpp
 *
 * [498] Diagonal Traverse
 */

// @lc code=start
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& g) {
    int m = g.size(), n = g[0].size();
    vector<int> res;
    res.reserve(m * n);

    for (int sum = 0; sum < m * n; ++sum) {
      if (sum & 1) {
        for (int i = max(0, sum - n + 1); i <= min(m - 1, sum); ++i)
          res.push_back(g[i][sum - i]);
      } else {
        for (int i = min(m - 1, sum); i >= max(0, sum - n + 1); --i)
          res.push_back(g[i][sum - i]);
      }
    }
    return res;
  }
};
// @lc code=end
