#include <vector>
using namespace std;

class Solution {
public:
  vector<int> printMatrix(vector<vector<int>> A) {
    vector<int> res;
    if (A.empty() || A[0].empty()) return res;
    
    int d[] = {0, 1, 0, -1, 0};
    int m = A.size(), n = A[0].size();
    int x = 0, y = 0, dir = 0;
    while (res.size() < m * n) {
      res.push_back(A[x][y]);
      A[x][y] = 0;

      int nx = x + d[dir], ny = y + d[dir + 1];
      if (!(0 <= nx && nx < m && 0 <= ny && ny < n && A[nx][ny])) {
        dir = (dir + 1) % 4;
        nx = x + d[dir], ny = y + d[dir + 1];
      }
      x = nx, y = ny;
    }

    return res;
  }
};