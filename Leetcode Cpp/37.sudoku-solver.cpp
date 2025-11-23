/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
 public:
  void solveSudoku(vector<vector<char>>& b) {
    auto check = [&](int pos) {
      int r = pos / 9, c = pos % 9;
      for (int i = 0; i < 9; i++) {
        if (b[r][i] == b[r][c] && i != c) return false;
        if (b[i][c] == b[r][c] && i != r) return false;
      }

      int i = r / 3 * 3, j = c / 3 * 3;
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++)
          if (b[i + k][j + l] == b[r][c] && i + k != r && j + l != c)
            return false;
      return true;
    };
    dfs(b, 0, check);
  }

  bool dfs(auto& b, int pos, auto& check) {
    while (pos < 81 && b[pos / 9][pos % 9] != '.') pos++;
    if (pos == 81) return true;
    for (int i = 1; i <= 9; i++) {
      b[pos / 9][pos % 9] = '0' + i;
      if (check(pos) && dfs(b, pos + 1, check)) return true;
      b[pos / 9][pos % 9] = '.';
    }
    return false;
  }
};
// @lc code=end
