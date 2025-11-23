/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    int M = *max_element(nums.begin(), nums.end());
    int cnt[M + 1];
    memset(cnt, 0, sizeof cnt);
    for (int x : nums) cnt[x]++;
    int f[M + 1][2];
    memset(f, 0, sizeof f);
    int res = 0;
    for (int i = 1; i <= M; i++) {
      f[i][0] = max(f[i - 1][0], f[i - 1][1]);
      f[i][1] = f[i - 1][0] + i * cnt[i];
      res = max({res, f[i][0], f[i][1]});
    }

    return res;
  }
};
// @lc code=end
