/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
 public:
  int totalNQueens(int n) {
    int res = 0;
    vector<int> pos(n);
    dfs(0, pos, n, res);
    return res;
  }

  void dfs(int u, auto& pos, int n, auto& res) {
    if (u == n) {
      res++;
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
