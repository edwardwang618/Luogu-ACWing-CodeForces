/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
 public:
  int change(int amount, vector<int>& cs) {
    int f[amount + 1];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int i = 0; i < cs.size(); i++)
      for (int j = cs[i]; j <= amount; j++)
        f[j] += f[j - cs[i]];
    return f[amount];
  }
};
// @lc code=end
