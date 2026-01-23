/*
 * @lc app=leetcode id=308 lang=cpp
 *
 * [308] Range Sum Query 2D - Mutable
 */

// @lc code=start
class NumMatrix {
public:
  int m, n;
  vector<vector<int>> tr, a;

  int lowbit(int x) { return x & -x; }
  void add(int x, int y, int d) {
    for (int i = x; i <= m; i += lowbit(i))
      for (int j = y; j <= n; j += lowbit(j))
        tr[i][j] += d;
  }
  int sum(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
      for (int j = y; j; j -= lowbit(j))
        res += tr[i][j];
    return res;
  }

  NumMatrix(vector<vector<int>> &b) {
    m = b.size(), n = b[0].size();
    tr.resize(m + 1, vector<int>(n + 1));
    a.resize(m + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        update(i, j, b[i][j]);
  }

  void update(int row, int col, int val) {
    row++, col++;
    add(row, col, val - a[row][col]);
    a[row][col] = val;
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    row1++, col1++, row2++, col2++;
    return sum(row2, col2) - sum(row1 - 1, col2) - sum(row2, col1 - 1) +
           sum(row1 - 1, col1 - 1);
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
