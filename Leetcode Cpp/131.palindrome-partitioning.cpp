/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
  vector<vector<string>> partition(string &s) {
    int n = s.size();
    vector<vector<bool>> f(n, vector<bool>(n));
    auto mark = [&](int l, int r) {
      while (0 <= l && r < n && s[l] == s[r])
        f[l--][r++] = true;
    };
    for (int c = 0; c < n; c++) {
      mark(c, c);
      mark(c, c + 1);
    }

    vector<vector<string>> res;
    vector<string> v;
    auto dfs = [&](auto &&self, int u) -> void {
      if (u == s.size()) {
        res.push_back(v);
        return;
      }

      for (int i = u; i < n; i++) {
        if (f[u][i]) {
          v.push_back(s.substr(u, i - u + 1));
          self(self, i + 1);
          v.pop_back();
        }
      }
    };
    dfs(dfs, 0);
    return res;
  }
};
// @lc code=end
