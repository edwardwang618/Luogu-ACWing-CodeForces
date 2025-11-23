/*
 * @lc app=leetcode id=1476 lang=cpp
 *
 * [1476] Subrectangle Queries
 */

// @lc code=start
class SubrectangleQueries {
 public:
  vector<vector<int>> g, qs;
  SubrectangleQueries(vector<vector<int>>& rectangle) { g.swap(rectangle); }

  void updateSubrectangle(int row1, int col1, int row2, int col2,
                          int newValue) {
    qs.push_back({row1, row2, col1, col2, newValue});
  }

  int getValue(int row, int col) {
    for (int i = int(qs.size()) - 1; i >= 0; i--) {
      int x1 = qs[i][0], x2 = qs[i][1], y1 = qs[i][2], y2 = qs[i][3];
      if (x1 <= row && row <= x2 && y1 <= col && col <= y2) return qs[i][4];
    }
    return g[row][col];
  }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
// @lc code=end
