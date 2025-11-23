/*
 * @lc app=leetcode id=348 lang=cpp
 *
 * [348] Design Tic-Tac-Toe
 */

// @lc code=start
class TicTacToe {
 private:
  vector<int> rows, cols;
  int diag, antidiag;
  int size;

 public:
  TicTacToe(int n) : rows(n, 0), cols(n, 0), diag(0), antidiag(0), size(n) {}

  int move(int row, int col, int player) {
    int add = player * 2 - 3;
    rows[row] += add;
    cols[col] += add;

    if (row == col) diag += add;
    if (row + col == size - 1) antidiag += add;

    if (rows[row] == size || cols[col] == size || diag == size ||
        antidiag == size)
      return 2;
    else if (rows[row] == -size || cols[col] == -size || diag == -size ||
             antidiag == -size)
      return 1;
    else
      return 0;
  }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
// @lc code=end
