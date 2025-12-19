/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

// @lc code=start
class Solution {
public:
  vector<string> buildArray(vector<int> &t, int n) {
    vector<string> res;
    for (int i = 1, idx = 0; i <= n; i++) {
      res.push_back("Push");
      if (i == t[idx])
        idx++;
      else
        res.push_back("Pop");

      if (idx == t.size())
        break;
    }
    return res;
  }
};
// @lc code=end
