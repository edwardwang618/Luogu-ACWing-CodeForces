/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& A, int k, int v) {
    map<int, int> mp;
    for (int i = 0; i < A.size(); i++) {
      int x = A[i];
      auto it = mp.lower_bound(x);
      if (it != mp.end() && abs(it->first - x) <= v) return true;
      if (it != mp.begin() && abs((--it)->first - x) <= v) return true;
      mp[x]++;
      if (i >= k && !--mp[A[i - k]]) mp.erase(A[i - k]);
    }

    return false;
  }
};
// @lc code=end
