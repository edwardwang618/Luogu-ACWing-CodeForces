/*
 * @lc app=leetcode id=1253 lang=cpp
 *
 * [1253] Reconstruct a 2-Row Binary Matrix
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> reconstructMatrix(int up, int low, vector<int>& cs) {
    int n = cs.size();
    vector<vector<int>> res(2, vector<int>(n));
    for (int i = 0; i < n; i++)
      if (cs[i] == 2) {
        res[0][i] = res[1][i] = 1;
        up--;
        low--;
      }
    if (up < 0 || low < 0) return vector<vector<int>>();
    for (int i = 0; i < n; i++)
      if (up && cs[i] == 1 && res[0][i] + res[1][i] == 0) {
        res[0][i] = 1;
        up--;
      }

    for (int i = 0; i < n; i++)
      if (low && cs[i] == 1 && res[0][i] + res[1][i] == 0) {
        res[1][i] = 1;
        low--;
      }
    if (up || low) return vector<vector<int>>();
    for (int i = 0; i < n; i++)
      if (res[0][i] + res[1][i] != cs[i]) return vector<vector<int>>();
    return res;
  }
};
// @lc code=end
