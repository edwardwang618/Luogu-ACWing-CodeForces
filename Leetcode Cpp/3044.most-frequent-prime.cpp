/*
 * @lc app=leetcode id=3044 lang=cpp
 *
 * [3044] Most Frequent Prime
 */

// @lc code=start
class Solution {
public:
  int mostFrequentPrime(vector<vector<int>> &a) {
    static auto f = [](int n) static {
      if (n < 2)
        return false;
      for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
          return false;
      return true;
    };

    static constexpr auto dir = []() {
      array<array<int, 2>, 8> dir;
      int idx = 0;
      for (int dx : {-1, 0, 1})
        for (int dy : {-1, 0, 1})
          if (dx || dy)
            dir[idx++] = {dx, dy};
      return dir;
    }();

    unordered_map<int, int> mp;
    int m = a.size(), n = a[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        for (auto [dx, dy] : dir) {
          int x = i, y = j;
          int v = 0;
          while (0 <= x && x < m && 0 <= y && y < n) {
            v = v * 10 + a[x][y];
            if (v >= 10 && f(v))
              mp[v]++;
            x += dx, y += dy;
          }
        }

    int res = -1, max_cnt = 0;
    for (auto &[k, v] : mp)
      if (v > max_cnt || v == max_cnt && k > res)
        res = k, max_cnt = v;
    return res;
  }
};
// @lc code=end
