/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
 public:
  void rotate(vector<vector<int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n - i; j++) swap(a[i][j], a[n - 1 - j][n - 1 - i]);
    for (int i = 0; i < n / 2; i++) swap(a[i], a[n - 1 - i]);
  }
};
// @lc code=end
