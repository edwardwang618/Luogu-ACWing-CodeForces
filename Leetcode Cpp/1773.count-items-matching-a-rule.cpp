/*
 * @lc app=leetcode id=1773 lang=cpp
 *
 * [1773] Count Items Matching a Rule
 */

// @lc code=start
class Solution {
 public:
  int countMatches(vector<vector<string>>& vec, string k, string v) {
    int res = 0;
    for (auto vs : vec)
      if (k == "type" && vs[0] == v || k == "color" && vs[1] == v ||
          k == "name" && vs[2] == v)
        res++;

    return res;
  }
};
// @lc code=end
