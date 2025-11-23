/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
 */

// @lc code=start
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& g) {
    unordered_map<int, vector<int>> mp;
    int max_sum = 0;
    for (int i = g.size() - 1; i >= 0; --i)
      for (int j = 0; j < g[i].size(); ++j) {
        mp[i + j].push_back(g[i][j]);
        max_sum = max(max_sum, i + j);
      }
    vector<int> res;
    for (int sum = 0; sum <= max_sum; ++sum)
      res.insert(res.end(), mp[sum].begin(), mp[sum].end());

    return res;
  }
};
// @lc code=end
