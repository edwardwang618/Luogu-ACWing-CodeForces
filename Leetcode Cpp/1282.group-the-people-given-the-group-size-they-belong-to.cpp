/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& gs) {
    vector<vector<int>> res;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < gs.size(); i++) mp[gs[i]].push_back(i);
    for (auto& [k, v] : mp)
      for (int i = 0; i < v.size() / k; i++)
        res.push_back(vector<int>(v.begin() + i * k, v.begin() + (i + 1) * k));
    return res;
  }
};
// @lc code=end
