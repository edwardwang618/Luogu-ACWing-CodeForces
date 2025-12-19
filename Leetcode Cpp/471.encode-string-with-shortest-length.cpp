/*
 * @lc app=leetcode id=471 lang=cpp
 *
 * [471] Encode String with Shortest Length
 */

// @lc code=start
class Solution {
public:
  string encode(string &s) {
    int n = s.size();
    vector<vector<string>> f(n, vector<string>(n));
    auto build_ne = [&](auto &p) {
      int m = p.size();
      p = " " + p;
      vector<int> ne(m + 1);
      for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
      }
      return ne;
    };
    for (int len = 1; len <= n; len++)
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        auto cur = s.substr(l, len);
        f[l][r] = cur;
        for (int k = l; k < r; k++) {
          auto &left = f[l][k], &right = f[k + 1][r];
          if (left.size() + right.size() < f[l][r].size())
            f[l][r] = left + right;
        }

        auto ne = build_ne(cur);
        int rep_len = len - ne[len];
        if (ne[len] && !(len % rep_len)) {
          int cnt = len / rep_len;
          auto p = to_string(cnt) + "[" + f[l][l + rep_len - 1] + "]";
          if (p.size() < f[l][r].size()) f[l][r] = move(p);
        }
      }
    return f[0][n - 1];
  }
};
// @lc code=end
