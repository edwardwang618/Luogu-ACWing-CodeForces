/*
 * @lc app=leetcode id=1124 lang=cpp
 *
 * [1124] Longest Well-Performing Interval
 */

// @lc code=start
class Solution {
 public:
  int longestWPI(vector<int>& A) {
    unordered_map<int, int> mp;
    int res = 0;
    for (int i = 0, sum = 0; i < A.size(); i++) {
      sum += A[i] > 8 ? 1 : -1;
      if (sum > 0) res = i + 1;
      else {
        if (mp.count(sum - 1)) res = max(res, i - mp[sum - 1]);
        if (!mp.count(sum)) mp[sum] = i;
      }
    }

    return res;
  }
};
// @lc code=end
