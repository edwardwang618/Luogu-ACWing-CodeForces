/*
 * @lc app=leetcode id=2078 lang=cpp
 *
 * [2078] Two Furthest Houses With Different Colors
 */

// @lc code=start
class Solution {
 public:
  int maxDistance(vector<int>& v) {
    unordered_map<int, int> mp;
    vector<int> vv;
    for (int i = 0; i < v.size(); i++)
      if (!mp.count(v[i])) {
        vv.push_back(v[i]);
        mp[v[i]] = i;
      }

    int res = 0;
    for (int i = v.size() - 1; i; i--)
      for (int j = 0; j < vv.size(); j++) {
        if (i <= mp[vv[j]]) break;
        if (v[i] != vv[j]) {
          res = max(res, i - mp[vv[j]]);
          break;
        }
      }

    return res;
  }
};
// @lc code=end
