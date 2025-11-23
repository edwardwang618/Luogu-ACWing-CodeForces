/*
 * @lc app=leetcode id=418 lang=cpp
 *
 * [418] a Screen Fitting
 */

// @lc code=start
class Solution {
 public:
  int wordsTyping(vector<string>& a, int rs, int cs) {
    unordered_map<int, int> mp;
    int c = 0, n = a.size();
    for (int i = 0; i < rs; i++) {
      int st = c % n;
      if (!mp.count(st)) {
        int cnt = 0, len = 0;
        for (int j = st; len < cs; j = (j + 1) % n, cnt++) {
          if (len + a[j].size() > cs) break;
          len += a[j].size() + 1;
        }
        c += cnt;
        mp[st] = cnt;
      } else c += mp[st];
    }
    return c / n;
  }
};
// @lc code=end
