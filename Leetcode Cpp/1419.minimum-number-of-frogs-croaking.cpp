/*
 * @lc app=leetcode id=1419 lang=cpp
 *
 * [1419] Minimum Number of Frogs Croaking
 */

// @lc code=start
class Solution {
 public:
  int minNumberOfFrogs(string s) {
    unordered_map<char, int> mp{
        {'c', 1}, {'r', 2}, {'o', 3}, {'a', 4}, {'k', 5}};
    int cnt[6] = {0}, res = 0;

    for (char ch : s) {
      int st = mp[ch];
      if (cnt[st - 1] > 0 || st == 1)
        cnt[st - 1]--, cnt[st]++;
      else return -1;

      int sum = 0;
      for (int i = 1; i <= 4; i++) sum += cnt[i];
      res = max(res, sum);
    }

    for (int i = 1; i <= 4; i++)
      if (cnt[i]) return -1;
    return res;
  }
};
// @lc code=end
