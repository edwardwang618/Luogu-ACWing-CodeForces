/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
 public:
  int longestOnes(vector<int>& a, int k) {
    int res = 0, zero_cnt = 0;
    for (int i = 0, j = 0; i < a.size(); i++) {
      zero_cnt += 1 - a[i];
      if (zero_cnt <= k)
        res = max(res, i - j + 1);
      else {
        while (zero_cnt > k) zero_cnt -= 1 - a[j++];
      }
    }

    return res;
  }
};
// @lc code=end
