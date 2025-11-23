/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 */

// @lc code=start
class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> res;
    for (int i = 1; i <= 9; i++) {
      int x = 0;
      for (int j = i; j <= 9; j++) {
        x = x * 10 + j;
        if (low <= x && x <= high) res.push_back(x);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
