/*
 * @lc app=leetcode id=458 lang=cpp
 *
 * [458] Poor Pigs
 */

// @lc code=start
class Solution {
public:
  int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    int k = minutesToTest / minutesToDie + 1;
    int n = buckets - 1, cnt = 0;
    while (n) {
      n /= k;
      cnt++;
    }
    return cnt;
  }
};
// @lc code=end
