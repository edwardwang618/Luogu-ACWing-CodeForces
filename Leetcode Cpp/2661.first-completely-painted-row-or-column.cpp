/*
 * @lc app=leetcode id=2661 lang=cpp
 *
 * [2661] First Completely Painted Row or Column
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  int firstCompleteIndex(vector<int>& a, vector<vector<int>>& M) {
    int m = M.size(), n = M[0].size();
    unordered_map<int, PII> mp;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) mp[M[i][j]] = {i, j};
    unordered_map<int, int> row_cnt, col_cnt;
    for (int i = 0; i < a.size(); i++) {
      auto &[x, y] = mp[a[i]];
      if (++row_cnt[x] == n || ++col_cnt[y] == m) return i;
    }
    return -1;
  }
};
// @lc code=end
