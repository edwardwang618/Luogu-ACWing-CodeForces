/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
class Solution {
 public:
  int heightChecker(vector<int>& a) {
    auto b = a;
    sort(b.begin(), b.end());
    int res = 0;
    for (int i = 0; i < a.size(); i++)
      if (a[i] != b[i]) res++;
    return res;
  }
};
// @lc code=end
