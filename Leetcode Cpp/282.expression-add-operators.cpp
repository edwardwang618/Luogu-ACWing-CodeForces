/*
 * @lc app=leetcode id=282 lang=cpp
 *
 * [282] Expression Add Operators
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  vector<string> addOperators(string s, int t) {
    vector<string> res;
    string str;
    dfs(0, str, 0, 1, t, s, res);
    return res;
  }

  void dfs(int u, string& str, ll a, ll b, ll t, string& s,
           vector<string>& res) {
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
        dfs(i + 1, str, 0, n, t, s, res);
      } else {
        str += "+" + sn;
        dfs(i + 1, str, a + b, n, t, s, res);
        str.resize(str.size() - 1 - sn.size());

        str += "-" + sn;
        dfs(i + 1, str, a + b, -n, t, s, res);
        str.resize(str.size() - 1 - sn.size());

        str += "*" + sn;
        dfs(i + 1, str, a, b * n, t, s, res);
        str.resize(str.size() - 1 - sn.size());
      }
    }
  }
};
// @lc code=end
