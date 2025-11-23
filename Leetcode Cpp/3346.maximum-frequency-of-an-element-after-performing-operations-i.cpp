/*
 * @lc app=leetcode id=3346 lang=cpp
 *
 * [3346] Maximum Frequency of an Element After Performing Operations I
 */

// @lc code=start
class Solution {
 public:
  int maxFrequency(vector<int>& a, int d, int ops) {
    int max_v = *max_element(a.begin(), a.end());
    int cnt[max_v], s[max_v + 1];
    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);
    for (int x : a) cnt[x - 1]++;
    for (int i = 1; i <= max_v; i++) s[i] = s[i - 1] + cnt[i - 1];
    int res = 1;
    for (int i = 0; i < max_v; i++) {
      int l = max(0, i - d), r = min(max_v - 1, i + d);
      res = max(res, min(s[r + 1] - s[l] - cnt[i], ops) + cnt[i]);
    }

    return res;
  }
};
// @lc code=end
