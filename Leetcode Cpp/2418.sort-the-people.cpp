/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 */

// @lc code=start
class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    int n = names.size();
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(i);
    sort(v.begin(), v.end(),
         [&](int i, int j) { return heights[i] > heights[j]; });

    vector<string> res;
    for (int i = 0; i < n; i++) res.push_back(names[v[i]]);
    return res;
  }
};
// @lc code=end
