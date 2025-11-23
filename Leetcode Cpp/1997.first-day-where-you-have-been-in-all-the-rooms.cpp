/*
 * @lc app=leetcode id=1997 lang=cpp
 *
 * [1997] First Day Where You Have Been in All the Rooms
 */

// @lc code=start
class Solution {
 public:
  int firstDayBeenInAllRooms(vector<int>& ne) {
    constexpr int MOD = 1e9 + 7;
    int n = ne.size();
    vector<int> f(n);
    f[0] = 0;
    for (int i = 1; i < n; i++)
      f[i] = ((f[i - 1] + 1 + (f[i - 1] - f[ne[i - 1]]) + 1) % MOD + MOD) % MOD;

    return f[n - 1];
  }
};
// @lc code=end
