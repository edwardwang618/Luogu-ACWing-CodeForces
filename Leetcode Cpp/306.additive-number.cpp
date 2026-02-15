/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
class Solution {
public:
  bool isAdditiveNumber(string &s) {
    auto add = [](const string &a, const string &b) {
      string c;
      int t = 0;
      for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0;) {
        if (i >= 0)
          t += a[i--] - '0';
        if (j >= 0)
          t += b[j--] - '0';
        c += t % 10 + '0';
        t /= 10;
      }
      if (t)
        c += '1';
      reverse(c.begin(), c.end());
      return c;
    };
    auto dfs = [&](this auto &&dfs, int u, const string &a,
                   const string &b) -> bool {
      if (a.size() && b.size()) {
        auto c = add(a, b);
        if (c.size() > s.size() - u)
          return false;
        if (c != s.substr(u, c.size()))
          return false;
        int nu = u + c.size();
        return nu == s.size() || dfs(nu, b, c);
      }
      for (int i = u; i < s.size(); i++) {
        if (i > u && s[u] == '0')
          return false;
        auto c = s.substr(u, i - u + 1);
        if (a.size()) {
          if (dfs(i + 1, a, c))
            return true;
        } else {
          if (dfs(i + 1, c, ""))
            return true;
        }
      }
      return false;
    };
    return dfs(0, "", "");
  }
};
// @lc code=end
