/*
 * @lc app=leetcode id=1275 lang=cpp
 *
 * [1275] Find Winner on a Tic Tac Toe Game
 */

// @lc code=start
class Solution {
 public:
  string tictactoe(vector<vector<int>>& moves) {
    char a[3][3] = {0};
    auto f = [&](int x, int y, char ch) {
      a[x][y] = ch;
      string res = ch == 'X' ? "A" : "B";
      for (int i = 0; i < 3; i++) {
        if (a[i][0] == ch && a[i][1] == ch && a[i][2] == ch) return res;
        if (a[0][i] == ch && a[1][i] == ch && a[2][i] == ch) return res;
        if (a[0][0] == ch && a[1][1] == ch && a[2][2] == ch) return res;
        if (a[0][2] == ch && a[1][1] == ch && a[2][0] == ch) return res;
      }
      return string();
    };
    bool b = true;
    for (auto& move : moves) {
      int x = move[0], y = move[1];
      auto res = f(x, y, b ? 'X' : 'O');
      if (res.size()) return res;
      b = !b;
    }

    return moves.size() < 9 ? "Pending" : "Draw";
  }
};
// @lc code=end
