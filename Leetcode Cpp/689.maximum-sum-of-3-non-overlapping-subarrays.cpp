/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& a, int k) {
    int n = a.size();
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
    vector<vector<int>> f(n + 2, vector<int>(4));
    for (int i = n - k + 1; i; i--)
      for (int j = 1; j <= 3; j++)
        f[i][j] = max(f[i + 1][j], f[i + k][j - 1] + s[i + k - 1] - s[i - 1]);

    vector<int> res;
    for (int x = 1, y = 3; y;) {
      while (f[x][y] != f[x + k][y - 1] + s[x + k - 1] - s[x - 1]) x++;
      res.push_back(x - 1);
      x += k, y--;
    }
    return res;
  }
};
// @lc code=end
