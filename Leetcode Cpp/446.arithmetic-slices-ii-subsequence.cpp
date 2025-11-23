/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& a) {
    int n = a.size(), res = 0;
    vector<unordered_map<long, int>> cnt(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++) {
        long diff = (long)a[i] - a[j];
        int s = 0;
        if (cnt[j].count(diff)) s = cnt[j][diff];
        cnt[i][diff] += s + 1;
        res += s;
      }

    return res;
  }
};
// @lc code=end
