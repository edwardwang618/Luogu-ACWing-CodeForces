/*
 * @lc app=leetcode id=1775 lang=cpp
 *
 * [1775] Equal Sum Arrays With Minimum Number of Operations
 */

// @lc code=start
class Solution {
 public:
  int minOperations(vector<int>& a1, vector<int>& a2) {
    int n = a1.size(), m = a2.size();
    if (n > m) return minOperations(a2, a1);

    if (m > 6 * n) return -1;
    vector<int> c1(7), c2(7);
    int s1 = 0, s2 = 0;
    for (int x : a1) c1[x]++, s1 += x;
    for (int x : a2) c2[x]++, s2 += x;

    int res = INT_MAX;
    for (int k = m; k <= 6 * n; k++)
      res = min(res, calc(s1, c1, k) + calc(s2, c2, k));
    return res;
  }

  int calc(int s, vector<int>& c, int t) {
    if (s == t) return 0;
    int res = 0;
    if (s >= t) {
      int d = s - t;
      for (int k = 6; k > 1; k--) {
        int kk = k - 1;
        if (c[k] * kk >= d)
          return res + (d + kk - 1) / kk;
        else
          res += c[k], d -= c[k] * kk;
      }
    } else {
      int d = t - s;
      for (int k = 1; k < 6; k++) {
        int kk = 6 - k;
        if (c[k] * kk >= d)
          return res += (d + kk - 1) / kk;
        else
          res += c[k], d -= c[k] * kk;
      }
    }
    return res;
  }
};
// @lc code=end
