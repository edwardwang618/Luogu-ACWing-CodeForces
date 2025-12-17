/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

// @lc code=start
class Solution {
public:
  int countStudents(vector<int> &ss, vector<int> &sands) {
    int cnt[2] = {0};
    for (int x : ss) cnt[x]++;
    for (int x : sands) {
      if (!cnt[x]) return cnt[0] + cnt[1];
      cnt[x]--;
    }
    return 0;
  }
};
// @lc code=end
