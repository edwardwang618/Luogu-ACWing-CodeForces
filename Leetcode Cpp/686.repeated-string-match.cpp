/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// @lc code=start
class Solution {
public:
  int repeatedStringMatch(string a, string b) {
    int n = a.size(), m = b.size();
    b = " " + b;
    auto ne = [&](string& p) {
      int m = p.size() - 1;
      vector<int> ne(m + 1);
      for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
      }
      return ne;
    }(b);
    auto kmp = [&](string& s, string& p) {
      int n = s.size() - 1, m = p.size() - 1;
      for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m) return true;
      }
      return false;
    };
    int cnt = (m + n - 1) / n;
    string s = " ";
    for (int i = 1; i <= cnt; i++) s += a;
    if (kmp(s, b)) return cnt;
    s += a;
    cnt++;
    return kmp(s, b) ? cnt : -1;
  }
};
// @lc code=end
