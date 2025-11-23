/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
 public:
  vector<vector<int>> sum;
  NumMatrix(vector<vector<int>>& a) {
    int m = a.size(), n = a[0].size();
    sum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        sum[i + 1][j + 1] = a[i][j] + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
  }

  int sumRegion(int x1, int y1, int x2, int y2) {
    return sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1] - sum[x2 + 1][y1] +
           sum[x1][y1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
