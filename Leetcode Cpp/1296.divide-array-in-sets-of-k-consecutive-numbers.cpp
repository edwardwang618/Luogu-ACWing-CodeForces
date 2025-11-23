/*
 * @lc app=leetcode id=1296 lang=cpp
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 */

// @lc code=start
class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k) return false;
    multiset<int> S(nums.begin(), nums.end());
    while (S.size()) {
      int x = *S.begin();
      for (int i = 0; i < k; i++) {
        auto it = S.find(x + i);
        if (it == S.end()) return false;
        S.erase(it);
      }
    }

    return true;
  }
};
// @lc code=end
