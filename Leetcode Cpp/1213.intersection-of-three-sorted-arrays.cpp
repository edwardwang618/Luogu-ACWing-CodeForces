/*
 * @lc app=leetcode id=1213 lang=cpp
 *
 * [1213] Intersection of Three Sorted Arrays
 */

// @lc code=start
class Solution {
 public:
  vector<int> arraysIntersection(vector<int>& a1, vector<int>& a2,
                                 vector<int>& a3) {
    map<int, int> mp;
    for (auto a : {a1, a2, a3})
      for (int x : a) mp[x]++;

    vector<int> res;
    for (auto& [k, v] : mp)
      if (v == 3) res.push_back(k);
    return res;
  }
};
// @lc code=end
