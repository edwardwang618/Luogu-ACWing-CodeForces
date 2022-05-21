#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int getMaxValue(vector<vector<int>>& grid) {
    int n = grid[0].size();
    vector<int> f(grid[0].begin(), grid[0].end());
    for (int j = 1; j < n; j++) f[j] += f[j - 1];
    for (int i = 1; i < grid.size(); i++)
      for (int j = 0; j < n; j++)
        if (!j) f[j] += grid[i][j];
        else f[j] = grid[i][j] + max(f[j], f[j - 1]);
    return f[n - 1];
  }
};