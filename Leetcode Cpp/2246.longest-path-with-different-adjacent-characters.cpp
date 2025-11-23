/*
 * @lc app=leetcode id=2246 lang=cpp
 *
 * [2246] Longest Path With Different Adjacent Characters
 */

// @lc code=start
class Solution {
 public:
  vector<int> h, e, ne;
  int idx;

  int longestPath(vector<int>& pa, string s) {
    int n = pa.size();
    h.resize(n, -1);
    e.resize(n);
    ne.resize(n);

    for (int i = 1; i < n; i++) {
      int a = pa[i], b = i;
      e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    }

    int res = 1;
    dfs(0, s, res);
    return res;
  }

  int dfs(int u, auto& s, int& res) {
    int len1 = 0, len2 = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
      int v = e[i];
      int len = dfs(v, s, res);
      if (s[v] != s[u]) {
        if (len >= len1)
          len2 = len1, len1 = len;
        else if (len > len2)
          len2 = len;
      }
    }

    res = max(res, 1 + len1 + len2);
    return 1 + len1;
  }
};
// @lc code=end
