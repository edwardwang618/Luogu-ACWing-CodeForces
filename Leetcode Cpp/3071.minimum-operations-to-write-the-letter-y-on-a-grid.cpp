/*
 * @lc app=leetcode id=3071 lang=cpp
 *
 * [3071] Minimum Operations to Write the Letter Y on a Grid
 */

// @lc code=start
class Solution {
 public:
  int minimumOperationsToWriteY(vector<vector<int>>& g) {
    int n = g.size();
    auto f = [&](int x, int y) {
      return (x <= n / 2 && (x == y || x + y == n - 1)) ||
             (x > n / 2 && y == n / 2);
    };
    unordered_map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) f(i, j) ? mp1[g[i][j]]++ : mp2[g[i][j]]++;

    int res = n * n;
    for (int i = 0; i <= 2; i++)
      for (int j = 0; j <= 2; j++)
        if (i != j) {
          int cnt = 0;
          for (auto& [k, v] : mp1)
            if (k != i) cnt += v;
          for (auto& [k, v] : mp2)
            if (k != j) cnt += v;
          res = min(res, cnt);
        }
    return res;
  }
};
// @lc code=end
