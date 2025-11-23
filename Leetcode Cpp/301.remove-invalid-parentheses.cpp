/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    int l = 0, r = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(')
        l++;
      else if (s[i] == ')') {
        if (!l)
          r++;
        else
          l--;
      }
    }

    vector<string> res;
    string t;
    dfs(0, s, t, 0, l, r, res);
    return res;
  }

  void dfs(int u, string& s, string& t, int diff, int l, int r,
           vector<string>& res) {
    if (u == s.size()) {
      if (!diff) res.push_back(t);
      return;
    }

    if (s[u] != '(' && s[u] != ')') {
      int i = u;
      while (i < s.size() && s[i] != '(' && s[i] != ')') t += s[i++];
      dfs(i, s, t, diff, l, r, res);
      t.erase(t.end() - (i - u), t.end());
      return;
    }

    if (s[u] == '(') {
      int i = u;
      while (i < s.size() && s[i] == '(') i++;
      for (int k = i - u; k >= 0; k--) {
        if (k <= l) dfs(i, s, t, diff + (i - u - k), l - k, r, res);
        t += '(';
      }
      t.erase(t.end() - (i - u + 1), t.end());
    } else {
      int i = u;
      while (i < s.size() && s[i] == ')') i++;
      for (int k = i - u; k >= 0; k--) {
        if (k <= r && diff - (i - u - k) >= 0)
          dfs(i, s, t, diff - (i - u - k), l, r - k, res);
        t += ')';
      }
      t.erase(t.end() - (i - u + 1), t.end());
    }
  }
};
// @lc code=end
