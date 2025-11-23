/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string t) {
    string s = " #";
    for (char ch : t) s = s + ch + "#";

    int n = s.size();
    int p[n], c;
    memset(p, 0, sizeof p);
    for (int i = 1, mr = 0, mid, max_rad = 0; i < n; i++) {
      if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
      else p[i] = 1;

      while (i - p[i] && i + p[i] < n && s[i - p[i]] == s[i + p[i]])
        p[i]++;

      if (i + p[i] > mr) {
        mr = i + p[i];
        mid = i;
      }

      if (p[i] > max_rad) {
        c = i;
        max_rad = p[i];
      }
    }

    string res;
    for (int i = c - p[c] + 1; i <= c + p[c] - 1; i++)
      if (s[i] != '#') res += s[i];

    return res;
  }

  // using UL = unsigned long;
  // vector<UL> pow, lh, rh;
  // UL P = 131;
  // string longestPalindrome(string s) {
  //   int n = s.size();
  //   s = " " + s;
  //   pow = vector<UL>(n + 2);
  //   lh = vector<UL>(n + 2);
  //   rh = vector<UL>(n + 2);
  //   pow[0] = 1;
  //   lh[0] = rh[n + 1] = 0;
  //   for (int i = 1; i <= n; i++) {
  //     pow[i] = pow[i - 1] * P;
  //     lh[i] = lh[i - 1] * P + s[i];
  //     rh[n - i + 1] = rh[n - i + 2] * P + s[n - i + 1];
  //   }

  //   string res;
  //   for (int i = 1; i <= n; i++) {
  //     int l = 0, r = min(i - 1, n - i);
  //     while (l < r) {
  //       int mid = l + (r - l + 1 >> 1);
  //       if (check(i - mid, i, i, i + mid)) l = mid;
  //       else r = mid - 1;
  //     }

  //     if (2 * l + 1 > res.size()) res = s.substr(i - l, 2 * l + 1);
  //     l = 0, r = min(i, n - i);
  //     while (l < r) {
  //       int mid = l + (r - l + 1 >> 1);
  //       if (check(i - mid + 1, i, i + 1, i + mid)) l = mid;
  //       else r = mid - 1;
  //     }
  //     if (2 * l > res.size()) res = s.substr(i - l + 1, 2 * l);
  //   }

  //   return res;
  // }

  // bool check(int l1, int r1, int l2, int r2) {
  //   return lh[r1] - lh[l1 - 1] * pow[r1 - l1 + 1] ==
  //          rh[l2] - rh[r2 + 1] * pow[r2 - l2 + 1];
  // }
};
// @lc code=end
