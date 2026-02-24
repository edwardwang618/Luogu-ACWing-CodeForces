/*
 * @lc app=leetcode id=3242 lang=cpp
 *
 * [3242] Design Neighbor Sum Service
 */

// @lc code=start
class NeighborSum {
  int n;
  vector<int> pos;
  vector<vector<int>> g;
  static constexpr int d[]{1, 0, -1, 0, 1};
  int id(int x, int y) { return x * n + y; }

public:
  NeighborSum(vector<vector<int>> &g) : n(g.size()), g(move(g)) {
    pos.resize(n * n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        pos[this->g[i][j]] = id(i, j);
  }

  int adjacentSum(int v) {
    int id = pos[v];
    int x = id / n, y = id % n;
    int sum = 0;
    for (int k = 0; k < 4; k++) {
      int nx = x + d[k], ny = y + d[k + 1];
      if (0 <= nx && nx < n && 0 <= ny && ny < n)
        sum += g[nx][ny];
    }
    return sum;
  }

  int diagonalSum(int v) {
    int id = pos[v];
    int x = id / n, y = id % n;
    int sum = 0;
    for (int dx : {-1, 1})
      for (int dy : {-1, 1}) {
        int nx = x + dx, ny = y + dy;
        if (0 <= nx && nx < n && 0 <= ny && ny < n)
          sum += g[nx][ny];
      }
    return sum;
  }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
// @lc code=end
