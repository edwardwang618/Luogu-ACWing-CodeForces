#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> numberOfDice(int n) {
    vector<vector<int>> f(2, vector<int>(6 * n + 1, 0));
    for (int i = 1; i <= 6; i++) f[0][i] = 1;
    for (int i = 1; i < n; i++) {
      fill(f[i & 1].begin(), f[i & 1].end(), 0);
      for (int j = i + 1; j <= 6 * (i + 1); j++)
        for (int k = 1; k <= 6; k++)
          if (j >= k) f[i & 1][j] += f[i - 1 & 1][j - k];
    }

    return {&f[n - 1 & 1][n], &f[n - 1 & 1][6 * n + 1]};
  }
};
