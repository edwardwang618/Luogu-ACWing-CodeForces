/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
 public:
  int findDuplicate(vector<int>& a) {
    int slow = 0, fast = 0;
    do {
      slow = a[slow];
      fast = a[a[fast]];
    } while (slow != fast);
    int cur = 0;
    while (cur != slow) cur = a[cur], slow = a[slow];
    return cur;
  }
};
// @lc code=end
