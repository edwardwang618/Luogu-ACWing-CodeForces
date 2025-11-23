/*
 * @lc app=leetcode id=1698 lang=cpp
 *
 * [1698] Number of Distinct Substrings in a String
 */

// @lc code=start
class Solution {
 public:
#define N 510
  int n, m;
  string s;
  int sa[N], rk[N], y[N], c[N], he[N];

  void get_sa() {
    for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[rk[i]]--] = i;

    for (int k = 1;; k <<= 1) {
      int num = 0;
      for (int i = n - k + 1; i <= n; i++) y[++num] = i;
      for (int i = 1; i <= n; i++)
        if (sa[i] > k) y[++num] = sa[i] - k;

      for (int i = 1; i <= m; i++) c[i] = 0;
      for (int i = 1; i <= n; i++) c[rk[i]]++;
      for (int i = 2; i <= m; i++) c[i] += c[i - 1];
      for (int i = n; i; i--) sa[c[rk[y[i]]]--] = y[i];
      swap(rk, y);
      rk[sa[1]] = num = 1;
      for (int i = 2; i <= n; i++)
        rk[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]
                        ? num
                        : ++num;
      if (num == n) break;
      m = num;
    }
  }

  void get_he() {
    for (int i = 1, k = 0; i <= n; i++) {
      if (rk[i] == 1) continue;
      int j = sa[rk[i] - 1];
      if (k) k--;
      while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
      he[rk[i]] = k;
    }
  }

  int countDistinct(string t) {
    n = t.size(), m = 'z';
    s = " " + t;
    get_sa();
    get_he();

    int res = n * (n + 1) / 2;
    for (int i = 2; i <= n; i++) res -= he[i];
    return res;
  }
};
// @lc code=end
