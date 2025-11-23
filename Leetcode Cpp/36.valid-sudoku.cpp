/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& b) {
    auto check = [&](unordered_map<char, int>& mp) {
      for (auto& [k, v] : mp)
        if (k != '.' && v > 1) return false;
      return true;
    };

    unordered_map<char, int> mp;
    for (int i = 0; i < 9; i++) {
      mp.clear();
      for (int j = 0; j < 9; j++) ++mp[b[i][j]];
      if (!check(mp)) return false;
      mp.clear();
      for (int j = 0; j < 9; j++) ++mp[b[j][i]];
      if (!check(mp)) return false;
    }

    for (int i = 0; i < 9; i += 3)
      for (int j = 0; j < 9; j += 3) {
        mp.clear();
        for (int k1 = 0; k1 < 3; k1++)
          for (int k2 = 0; k2 < 3; k2++) ++mp[b[i + k1][j + k2]];
        if (!check(mp)) return false;
      }
    return true;
  }
};
// @lc code=end
