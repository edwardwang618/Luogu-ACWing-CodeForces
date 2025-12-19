/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
 public:
  bool makesquare(vector<int> &a) {
    int len = 0;
    for (auto &x : a) len += x;
    if (len % 4) return false;
    len /= 4;

    sort(a.begin(), a.end(), greater<>{});
    int n = a.size();
    vector<bool> vis(n);

    auto dfs = [&](auto&& self, int u, int cur_len, int cnt) ->bool {
      if (cnt == 3) return true;
      if (cur_len == len) return self(self, 0, 0, cnt + 1);

      for (int i = u; i < n; i++) {
        if (vis[i]) continue;
        if (cur_len + a[i] > len) continue;
        cur_len += a[i];
        vis[i] = true;
        if (self(self, u + 1, cur_len, cnt)) return true;
        cur_len -= a[i];
        vis[i] = false;
        if (!cur_len || cur_len + a[i] == len) return false;
        while (i + 1 < n && a[i + 1] == a[i]) i++;
      }

      return false;
    };
    return dfs(dfs, 0, 0, 0);
  }
};
// @lc code=end
