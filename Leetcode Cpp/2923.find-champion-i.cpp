/*
 * @lc app=leetcode id=2923 lang=cpp
 *
 * [2923] Find Champion I
 */

// @lc code=start
class Solution {
public:
  int findChampion(vector<vector<int>> &g) {
    int n = g.size();
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int x : g[i])
        sum += x;
      if (sum == n - 1)
        return i;
    }
    return -1;
  }
};
// @lc code=end
