/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
 public:
  int lastStoneWeightII(vector<int>& ss) {
    int sum = 0, n = ss.size();
    for (auto x : ss) sum += x;
    int f[sum / 2 + 1];
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++)
      for (int j = sum / 2; j >= ss[i - 1]; j--)
        f[j] = max(f[j], f[j - ss[i - 1]] + ss[i - 1]);

    return sum - 2 * f[sum / 2];
  }
};
// @lc code=end
