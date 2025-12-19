/*
 * @lc app=leetcode id=1434 lang=cpp
 *
 * [1434] Number of Ways to Wear Different Hats to Each Other
 */

// @lc code=start
class Solution {
public:
  int numberWays(vector<vector<int>> &hs) {
    static constexpr int MOD = 1e9 + 7;
    int n = hs.size(), m = 0;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < hs.size(); i++) {
      auto &h = hs[i];
      for (int x : h) {
        mp[x].push_back(i);
        m = max(m, x);
      }
    }

    vector<vector<int>> f(2, vector<int>(1 << n));
    f[0][0] = 1;
    for (int i = 1; i <= m; i++) {
      f[i & 1] = f[i - 1 & 1];
      if (auto it = mp.find(i); it != mp.end()) {
        for (int j : it->second) {
          for (int k = 0; k < 1 << n; k++) {
            if (k >> j & 1) {
              int ps = k ^ (1 << j);
              f[i & 1][k] = (f[i & 1][k] + f[i - 1 & 1][ps]) % MOD;
            }
          }
        }
      }
    }
    return f[m & 1][(1 << n) - 1];
  }
};
// @lc code=end
