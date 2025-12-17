/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
  // string longestPalindrome(string t) {
  //   string s = " #";
  //   for (char ch : t) s = s + ch + "#";

  //   int n = s.size();
  //   int p[n], c;
  //   memset(p, 0, sizeof p);
  //   for (int i = 1, mr = 0, mid, max_rad = 0; i < n; i++) {
  //     if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
  //     else p[i] = 1;

  //     while (i - p[i] && i + p[i] < n && s[i - p[i]] == s[i + p[i]])
  //       p[i]++;

  //     if (i + p[i] > mr) {
  //       mr = i + p[i];
  //       mid = i;
  //     }

  //     if (p[i] > max_rad) {
  //       c = i;
  //       max_rad = p[i];
  //     }
  //   }

  //   string res;
  //   for (int i = c - p[c] + 1; i <= c + p[c] - 1; i++)
  //     if (s[i] != '#') res += s[i];

  //   return res;
  // }

  string longestPalindrome(string s) {
    using ull = unsigned long long;
    string t = " $";
    t.reserve(s.size() * 2 + 2);
    for (char ch : s) {
      t += ch;
      t += '$';
    }
    s = move(t);
    int n = s.size() - 1;
    vector<ull> lh(n + 1), rh(n + 1), pow(n + 1);
    pow[0] = 1;
    constexpr ull P = 131;
    for (int i = 1; i <= n; i++) {
      lh[i] = lh[i - 1] * P + s[i];
      rh[i] = rh[i - 1] * P + s[n + 1 - i];
      pow[i] = pow[i - 1] * P;
    }
    auto ha = [&](int l, int r, auto &h) {
      return h[r] - h[l - 1] * pow[r - l + 1];
    };
    auto lha = [&](int l, int r) { return ha(l, r, lh); };
    auto rha = [&](int l, int r) { return ha(n + 1 - r, n + 1 - l, rh); };

    int res_l, res_r, max_len = 0;
    for (int i = 1; i <= n; i++) {
      int l = 0, r = min(i - 1, n - i);
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (lha(i - mid, i) == rha(i, i + mid))
          l = mid;
        else
          r = mid - 1;
      }
      if (l > max_len)
        res_l = i - l, res_r = i + l, max_len = l;
    }
    string res;
    res.reserve(max_len);
    for (int i = res_l; i <= res_r; i++)
      if (s[i] != '$')
        res += s[i];
    return res;
  }
};
// @lc code=end
