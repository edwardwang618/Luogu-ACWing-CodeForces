/*
 * @lc app=leetcode id=943 lang=cpp
 *
 * [943] Find the Shortest Superstring
 */

// @lc code=start
class Solution {
 public:
  string shortestSuperstring(vector<string> &ws) {
    int n = ws.size();
    auto calc = [&](int i, int j) {
      string &s1 = ws[i], &s2 = ws[j];
      for (int k = min(s1.size(), s2.size()); k; k--)
        if (s1.substr(s1.size() - k) == s2.substr(0, k)) return k;
      return 0;
    };
    vector<vector<int>> p(n, vector<int>(n));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i != j) p[i][j] = calc(i, j);

    const int INF = 2e8;
    vector<vector<int>> f(1 << n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) f[1 << i][i] = ws[i].size();
    for (int i = 0; i < 1 << n; i++)
      for (int j = 0; j < n; j++)
        if (i >> j & 1)
          for (int k = 0; k < n; k++)
            if (!(i >> k & 1))
              f[i | (1 << k)][k] = min(f[i | (1 << k)][k],
                                       f[i][j] + (int)ws[k].size() - p[j][k]);

    int i = (1 << n) - 1, j = -1;
    for (int k = 0; k < n; k++)
      if (!~j || f[i][k] < f[i][j]) j = k;
    vector<int> v;
    while (i) {
      v.push_back(j);
      i -= 1 << j;
      for (int k = 0; k < n; k++)
        if ((i >> k & 1) &&
            f[i][k] + ws[j].size() - p[k][j] == f[i + (1 << j)][j]) {
          j = k;
          break;
        }
    }
    reverse(v.begin(), v.end());
    string s = ws[v[0]];
    for (i = 1; i < n; i++) s += ws[v[i]].substr(p[v[i - 1]][v[i]]);
    return s;
  }
};
// @lc code=end
