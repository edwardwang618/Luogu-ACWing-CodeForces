/*
 * @lc app=leetcode id=2363 lang=cpp
 *
 * [2363] Merge Similar Items
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>>& i1,
                                        vector<vector<int>>& i2) {
    map<int, int> mp;
    for (auto& v : i1) mp[v[0]] += v[1];
    for (auto& v : i2) mp[v[0]] += v[1];
    vector<vector<int>> res;
    for (auto& [k, v] : mp) res.push_back({k, v});
    return res;
  }
};
// @lc code=end
