/*
 * @lc app=leetcode id=1830 lang=cpp
 *
 * [1830] Minimum Number of Operations to Make String Sorted
 */

// @lc code=start
// class Solution {
//  public:
//   vector<int> tr;
//   int n;
// #define lowbit(x) (x & -x)

//   void add(int k, int x) {
//     for (; k <= n; k += lowbit(k)) tr[k] += x;
//   }

//   int sum(int k) {
//     int res = 0;
//     for (; k; k -= lowbit(k)) res += tr[k];
//     return res;
//   }

//   int makeStringSorted(string s) {
//     const int P = 1e9 + 7;
//     n = *max_element(s.begin(), s.end()) - 'a' + 1;
//     tr.resize(n + 1);
//     auto fast_pow = [&](long x, int pow = P - 2) {
//       long res = 1;
//       while (pow) {
//         if (pow & 1) res = res % P * x % P;
//         pow >>= 1;
//         x = x % P * x % P;
//       }

//       return res;
//     };

//     long res = 0, fact = 1, mult = 1;
//     int cnt[27];
//     memset(cnt, 0, sizeof cnt);
//     for (int i = s.size() - 1; i >= 0; i--) {
//       int x = s[i] - 'a' + 1;
//       cnt[x]++;
//       mult = mult * fast_pow(cnt[x]) % P;
//       add(x, 1);
//       res = (res + fact * mult % P * sum(x - 1)) % P;
//       fact = (s.size() - i) * fact % P;
//     }

//     return res;
//   }
// };

class Solution {
 public:
  int makeStringSorted(string s) {
    const int P = 1e9 + 7;
    int n = s.size();
    long f[n + 1], g[n + 1];
    f[0] = g[0] = 1;
    auto fast_pow = [&](long a, int b) {
      long res = 1;
      while (b) {
        if (b & 1) res = res * a % P;
        a = a * a % P;
        b >>= 1;
      }

      return res;
    };
    for (int i = 1; i <= n; i++) {
      f[i] = f[i - 1] * i % P;
      g[i] = fast_pow(f[i], P - 2);
    }

    int res = 0, cnt[26], sum = n;
    memset(cnt, 0, sizeof cnt);
    auto calc = [&](int sum) {
      int res = f[sum];
      for (int i = 0; i < 26; i++) res = (long)res * g[cnt[i]] % P;
      return res;
    };
    for (char ch : s) cnt[ch - 'a']++;
    for (int k = 0; k < s.size(); k++) {
      int x = s[k] - 'a';
      for (int i = 0; i < x; i++) {
        if (!cnt[i]) continue;
        cnt[i]--;
        res = (res + calc(n - 1 - k)) % P;
        cnt[i]++;
      }

      cnt[x]--;
    }

    return res;
  }
};

// @lc code=end
