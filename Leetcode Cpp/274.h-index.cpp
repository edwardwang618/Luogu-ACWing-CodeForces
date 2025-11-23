/*
 * @lc app=leetcode id=274 lang=cpp
 *
 * [274] H-Index
 */

// @lc code=start
class Solution {
 public:
  int hIndex(vector<int>& cs) {
    int n = cs.size();
    vector<int> cnt(n + 1);
    for (int x : cs) cnt[min(n, x)]++;
    int sum = 0;
    for (int i = n; i >= 0; i--) {
      sum += cnt[i];
      if (i <= sum) return i;
    }
    return 0;
  }
};
// @lc code=end
