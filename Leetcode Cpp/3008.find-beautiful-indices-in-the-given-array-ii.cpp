/*
 * @lc app=leetcode id=3008 lang=cpp
 *
 * [3008] Find Beautiful Indices in the Given Array II
 */

// @lc code=start
class Solution {
public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    s = " " + s;
    a = " " + a;
    b = " " + b;
    auto f = [](auto& s, auto& p) {
      int m = p.size() - 1, n = s.size() - 1;
      vector<int> ne(m + 1);
      for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
      }
      vector<int> res;
      for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) {
          res.push_back(i - j);
          j = ne[j];
        }
      }
      return res;
    };

    auto va = f(s, a), vb = f(s, b);
    int j = 0;
    vector<int> res;
    for (int i : va) {
      int l = i - k, r = i + k;
      while (j < vb.size() && vb[j] < l) j++;
      if (j < vb.size() && vb[j] <= r) res.push_back(i);
    }
    return res;
  }
};
// @lc code=end
