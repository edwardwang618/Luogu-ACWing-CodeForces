/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  vector<string> addOperators(string &s, int t) {
    vector<string> res;
    string str;
    auto dfs = [&](this auto &&dfs, int u, ll a, ll b) -> void {
      if (u == s.size()) {
        if (a + b == t) res.push_back(str);
        return;
      }

      ll n = 0;
      for (int i = u; i < s.size(); i++) {
        if (i > u && s[u] == '0') break;
        n = n * 10 + s[i] - '0';
        auto sn = to_string(n);
        if (!u) {
          str = sn;
          dfs(i + 1, 0, n);
        } else {
          str += "+" + sn;
          dfs(i + 1, a + b, n);
          str.resize(str.size() - 1 - sn.size());

          str += "-" + sn;
          dfs(i + 1, a + b, -n);
          str.resize(str.size() - 1 - sn.size());

          str += "*" + sn;
          dfs(i + 1, a, b * n);
          str.resize(str.size() - 1 - sn.size());
        }
      }
    };
    dfs(0, 0, 1);
    return res;
  }
};
// @lc code=end
