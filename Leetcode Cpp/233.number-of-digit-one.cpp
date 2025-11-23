/*
 * @lc app=leetcode id=233 lang=cpp
 *
 * [233] Number of Digit One
 */

// @lc code=start
class Solution {
 public:
  int countDigitOne(int n) {
    vector<int> a;
    while (n) a.push_back(n % 10), n /= 10;
    reverse(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
      int d = a[i];
      int l = 0, r = 0, p = 1;
      for (int j = 0; j < i; j++) l = l * 10 + a[j];
      for (int j = i + 1; j < a.size(); j++) {
        r = r * 10 + a[j];
        p = p * 10;
      }

      if (!d)
        res += l * p;
      else if (d == 1)
        res += l * p + r + 1;
      else
        res += (l + 1) * p;
    }

    return res;
  }
};
// @lc code=end
