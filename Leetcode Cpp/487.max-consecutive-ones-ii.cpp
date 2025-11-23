/*
 * @lc app=leetcode id=487 lang=cpp
 *
 * [487] Max Consecutive Ones II
 */

// @lc code=start
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& a) {
    int cnt[2] = {0}, res = 0;
    for (int i = 0, j = 0; i < a.size(); i++) {
      cnt[a[i]]++;
      while (cnt[0] > 1) cnt[a[j++]]--;
      res = max(res, i - j + 1);
    }
    return res;
  }
};
// @lc code=end
