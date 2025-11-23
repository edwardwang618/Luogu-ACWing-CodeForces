/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
 public:
  int minScoreTriangulation(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> f(n, vector<int>(n, -1));
    return dfs(0, n - 1, v, f);
  }

  int dfs(int l, int r, vector<int>& v, vector<vector<int>>& f) {
    if (~f[l][r]) return f[l][r];
    if (l + 1 == r) return f[l][r] = 0;
    int res = INT_MAX;
    for (int i = l + 1; i < r; i++)
      res = min(res, v[l] * v[i] * v[r] + dfs(l, i, v, f) + dfs(i, r, v, f));

    return f[l][r] = res;
  }
};
// @lc code=end
