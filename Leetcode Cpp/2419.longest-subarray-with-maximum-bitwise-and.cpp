/*
 * @lc app=leetcode id=2419 lang=cpp
 *
 * [2419] Longest Subarray With Maximum Bitwise AND
 */

// @lc code=start
class Solution {
 public:
  int longestSubarray(vector<int>& a) {
    int res = 0, max_v = -1;
    for (int i = 0; i < a.size(); i++) {
      int j = i;
      while (j < a.size() && a[j] == a[i]) j++;
      if (a[i] > max_v) {
        max_v = a[i];
        res = j - i;
      } else if (a[i] == max_v)
        res = max(res, j - i);

      i = j - 1;
    }

    return res;
  }
};
// @lc code=end
