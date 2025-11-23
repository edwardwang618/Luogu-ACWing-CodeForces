/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    if (!n) return res;
    vector<int> pos(n);
    dfs(0, pos, n, res);
    return res;
  }

  void dfs(int u, auto& pos, int n, auto& res) {
    if (u == n) {
      vector<string> v(n, string(n, '.'));
      for (int i = 0; i < n; i++) v[i][pos[i]] = 'Q';
      res.push_back(v);
      return;
    }
    static vector<bool> col(n), diag(2 * n - 1), udiag(2 * n - 1);
    for (int i = 0; i < n; i++) {
      if (col[i] || diag[u - i + n - 1] || udiag[u + i]) continue;
      pos[u] = i;
      col[i] = diag[u - i + n - 1] = udiag[u + i] = true;
      dfs(u + 1, pos, n, res);
      col[i] = diag[u - i + n - 1] = udiag[u + i] = false;
    }
  }
};
// @lc code=end
