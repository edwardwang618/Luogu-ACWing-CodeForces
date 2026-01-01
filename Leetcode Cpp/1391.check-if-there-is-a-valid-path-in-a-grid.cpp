/*
 * @lc app=leetcode id=1391 lang=cpp
 *
 * [1391] Check if There is a Valid Path in a Grid
 */

// @lc code=start
class Solution {
public:
  bool hasValidPath(vector<vector<int>> &g) {
    int m = g.size(), n = g[0].size();
    auto id = [&](int x, int y) { return x * n + y; };
    vector<int> p(m * n);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto &&find, int x) -> int {
      return x == p[x] ? x : p[x] = find(p[x]);
    };
    auto merge = [&](int a, int b) {
      int pa = find(a), pb = find(b);
      if (pa != pb)
        p[pa] = pb;
    };

    // {up, down, left, right}
    static vector<array<bool, 4>> opens = {
        {},                         // 0 (unused)
        {false, false, true, true}, // 1: ─
        {true, true, false, false}, // 2: │
        {false, true, true, false}, // 3: ┘ (down-left)
        {false, true, false, true}, // 4: └ (down-right)
        {true, false, true, false}, // 5: ┐ (up-left)
        {true, false, false, true}, // 6: ┌ (up-right)
    };

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        int t = g[i][j];
        if (i > 0 && opens[t][0] && opens[g[i - 1][j]][1])
          merge(id(i, j), id(i - 1, j));
        if (j > 0 && opens[t][2] && opens[g[i][j - 1]][3])
          merge(id(i, j), id(i, j - 1));
      }

    return find(id(0, 0)) == find(id(m - 1, n - 1));
  }
};
// @lc code=end
