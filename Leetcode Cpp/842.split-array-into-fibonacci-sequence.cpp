/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */

// @lc code=start
class Solution {
public:
  vector<int> splitIntoFibonacci(string &s) {
    vector<int> res;
    auto dfs = [&](this auto &&dfs, int u) -> bool {
      if (u == s.size()) {
        return res.size() >= 3;
      }

      using ll = long long;
      ll n = 0;
      for (int i = u; i < s.size(); i++) {
        if (i > u && s[u] == '0') return false;
        n = n * 10 + s[i] - '0';
        if (n > INT_MAX) return false;
        if (res.size() < 2) {
          res.push_back(n);
          if (dfs(i + 1)) return true;
          res.pop_back();
        } else {
          int sz = res.size();
          ll n1 = res[sz - 1], n2 = res[sz - 2];
          if (n == n1 + n2) {
            res.push_back(n);
            if (dfs(i + 1)) return true;
            res.pop_back();
          } else if (n > n1 + n2) return false;
        }
      }
      return false;
    };
    dfs(0);
    return res;
  }
};
// @lc code=end
