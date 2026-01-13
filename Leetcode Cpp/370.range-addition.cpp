/*
 * @lc app=leetcode id=370 lang=cpp
 *
 * [370] Range Addition
 */

// @lc code=start
class Solution {
public:
  vector<int> getModifiedArray(int n, vector<vector<int>> &vs) {
    vector<int> res(n);
    for (auto &v : vs) {
      int l = v[0], r = v[1], x = v[2];
      res[l] += x;
      if (r + 1 < n) res[r + 1] -= x;
    }
    for (int i = 0; i + 1 < n; i++) res[i + 1] += res[i];
    return res;
  }
};
// @lc code=end
