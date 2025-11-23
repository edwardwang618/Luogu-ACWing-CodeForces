/*
 * @lc app=leetcode id=573 lang=cpp
 *
 * [573] Squirrel Simulation
 */

// @lc code=start
class Solution {
 public:
  int minDistance(int height, int width, vector<int>& tree,
                  vector<int>& squirrel, vector<vector<int>>& nuts) {
    int res = 0, d = INT_MIN;
    auto dist = [&](vector<int>& a, vector<int>& b) {
      return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    };

    for (auto nut : nuts) {
      res += dist(nut, tree) * 2;
      d = max(d, dist(nut, tree) - dist(nut, squirrel));
    }

    return res - d;
  }
};
// @lc code=end
