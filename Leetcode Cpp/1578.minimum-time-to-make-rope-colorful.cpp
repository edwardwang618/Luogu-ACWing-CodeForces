/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution {
 public:
  int minCost(string s, vector<int>& cost) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
      int j = i, mx = 0, sum = 0;
      while (j < s.size() && s[j] == s[i]) {
        mx = max(mx, cost[j]);
        sum += cost[j++];
      }
      i = j - 1;
      res += sum - mx;
    }

    return res;
  }
};
// @lc code=end
