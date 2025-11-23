/*
 * @lc app=leetcode id=2019 lang=cpp
 *
 * [2019] The Score of Students Solving Math Expression
 */

// @lc code=start
class Solution {
 public:
  int scoreOfStudents(string s, vector<int> &v) {
    int a = calc(s);
    int res = 0, n = s.size();
    vector<vector<unordered_set<int> *>> f(
        n, vector<unordered_set<int> *>(n, nullptr));
    auto *st = dfs(s, 0, n - 1, f);
    for (int x : v)
      if (x == a) res += 5;
      else if (st->count(x)) res += 2;

    return res;
  }

  unordered_set<int> *dfs(string &s, int l, int r,
                          vector<vector<unordered_set<int> *>> &f) {
    if (f[l][r]) return f[l][r];
    f[l][r] = new unordered_set<int>();
    if (l == r) f[l][r]->insert(s[l] - '0');
    else
      for (int i = l + 1; i < r; i++)
        if (!isdigit(s[i]))
          for (int x : *dfs(s, l, i - 1, f))
            for (int y : *dfs(s, i + 1, r, f)) {
              int res = 0;
              s[i] == '+' ? res = x + y : res = x * y;
              if (0 <= res && res <= 1000) f[l][r]->insert(res);
            }

    return f[l][r];
  }

  int calc(string &s) {
    stack<int> stk;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (isdigit(ch)) 
        if (i && s[i - 1] == '*') {
          int t = stk.top(); stk.pop();
          stk.push(t * (ch - '0'));
        } else stk.push(ch - '0');
    }

    int res = 0;
    while (stk.size()) {
      res += stk.top(); stk.pop();
    }
    return res;
  }
};
// @lc code=end
