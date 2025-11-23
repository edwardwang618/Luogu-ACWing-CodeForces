/*
 * @lc app=leetcode id=1894 lang=cpp
 *
 * [1894] Find the Student that Will Replace the Chalk
 */

// @lc code=start
class Solution {
 public:
  int chalkReplacer(vector<int>& chalk, int k) {
    long sum = accumulate(chalk.begin(), chalk.end(), 0L);
    k %= sum;
    for (int i = 0; i < chalk.size(); i++) {
      if (k < chalk[i]) return i;
      k -= chalk[i];
    }
    return -1;
  }
};
// @lc code=end
