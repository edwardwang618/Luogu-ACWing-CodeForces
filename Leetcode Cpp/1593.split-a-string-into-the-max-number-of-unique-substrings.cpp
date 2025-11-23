/*
 * @lc app=leetcode id=1593 lang=cpp
 *
 * [1593] Split a String Into the Max Number of Unique Substrings
 */

// @lc code=start
class Solution {
 public:
  using UL = unsigned long;
  int maxUniqueSplit(string s) {
    UL P = 131;
    int n = s.size();
    vector<UL> pow(n + 1), ha(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
      pow[i] = pow[i - 1] * P;
      ha[i] = ha[i - 1] * P + s[i - 1];
    }

    unordered_set<UL> st;
    return dfs(0, s, st, pow, ha);
  }

  int dfs(int u, string& s, unordered_set<UL>& st, vector<UL>& pow,
          vector<UL>& ha) {
    if (u == s.size()) return 0;
    int res = -1;
    for (int i = u; i < s.size(); i++) {
      auto h = hash(u, i, pow, ha);
      if (st.count(h)) continue;
      st.insert(h);
      int t = dfs(i + 1, s, st, pow, ha);
      if (~t) res = max(res, 1 + t);
      st.erase(h);
    }

    return res;
  }

  UL hash(int l, int r, vector<UL>& pow, vector<UL>& ha) {
    return ha[r + 1] - ha[l] * pow[r - l + 1];
  }
};
// @lc code=end
