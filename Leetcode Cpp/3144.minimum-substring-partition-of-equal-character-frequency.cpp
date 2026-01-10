/*
 * @lc app=leetcode id=3144 lang=cpp
 *
 * [3144] Minimum Substring Partition of Equal Character Frequency
 */

// @lc code=start
class Solution {
public:
  int minimumSubstringsInPartition(string &s) {
    int n = s.size();
    constexpr int INF = 2e9;
    vector<int> f(n + 1, INF);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
      int cnt[26]{};
      int max_freq = 0, kinds = 0;
      for (int j = i - 1; j >= 0; j--) {
        int idx = s[j] - 'a';
        if (!cnt[idx]++) kinds++;
        max_freq = max(max_freq, cnt[idx]);

        int len = i - j;
        if (kinds * max_freq == len) f[i] = min(f[i], f[j] + 1);
      }
    }
    return f[n];
  }
};
// @lc code=end
