/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& A, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < A.size(); i++) {
      if (mp.count(A[i]) && i - mp[A[i]] <= k) return true;
      mp[A[i]] = i;
    }

    return false;
  }
};
// @lc code=end
