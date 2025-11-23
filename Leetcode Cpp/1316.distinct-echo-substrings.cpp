/*
 * @lc app=leetcode id=1316 lang=cpp
 *
 * [1316] Distinct Echo Substrings
 */

// @lc code=start
class Solution {
 public:
  using ULL = unsigned long long;
  ULL P = 131;
  int distinctEchoSubstrings(string s) {
    int n = s.size();
    s = " " + s;
    vector<ULL> h(n + 1), pow(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++) {
      pow[i] = pow[i - 1] * P;
      h[i] = h[i - 1] * P + s[i];
    }

    unordered_set<ULL> set;
    for (int i = 1; i <= n; i++)
      for (int j = 1; i + j * 2 - 1 <= n; j++) {
        ULL left = get(i, i + j - 1, h, pow),
            right = get(i + j, i + 2 * j - 1, h, pow);
        if (left == right) set.insert(left);
      }

    return set.size();
  }

  ULL get(int l, int r, vector<ULL>& h, vector<ULL>& pow) {
    return h[r] - h[l - 1] * pow[r - l + 1];
  }
};
// @lc code=end
