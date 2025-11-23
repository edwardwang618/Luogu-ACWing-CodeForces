/*
 * @lc app=leetcode id=750 lang=cpp
 *
 * [750] Number Of Corner Rectangles
 */

// @lc code=start
class Solution {
 public:
  int countCornerRectangles(vector<vector<int>>& g) {
    int res = 0;
    unordered_map<int, int> mp;
    for (auto& row : g) {
      for (int i = 0; i < row.size(); i++) {
        if (row[i] == 1) {
          for (int j = i + 1; j < row.size(); j++)
            if (row[j] == 1) {
              int ha = i * 200 + j;
              res += mp[ha]++;
            }
        }
      }
    }

    return res;
  }
};
// @lc code=end
