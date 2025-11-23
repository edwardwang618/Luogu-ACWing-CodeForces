/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& d) {
    int t = 1;
    for (int i = d.size() - 1; i >= 0; i--) {
      t += d[i];
      d[i] = t % 10;
      t /= 10;
    }

    if (t) d.insert(d.begin(), 1);
    return d;
  }
};
// @lc code=end
