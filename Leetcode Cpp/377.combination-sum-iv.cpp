/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

// @lc code=start
class Solution {
 public:
  using ui = unsigned int;
  int combinationSum4(vector<int>& a, int target) {
    ui f[target + 1];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (long i = 1; i <= target; i++)
      for (int j = 0; j < a.size(); j++)
        if (i >= a[j]) f[i] += f[i - a[j]];
    return f[target];
  }
};
// @lc code=end
