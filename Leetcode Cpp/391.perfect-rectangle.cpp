/*
 * @lc app=leetcode id=391 lang=cpp
 *
 * [391] Perfect Rectangle
 */

// @lc code=start
class Solution {
 public:
#define x first
#define y second
  bool isRectangleCover(vector<vector<int>>& vs) {
    auto ha = [](const pair<int, int>& p) {
      return hash<int>()(p.x) ^ hash<int>()(p.y);
    };
    unordered_map<pair<int, int>, int, decltype(ha)> mp;
    for (auto& v : vs) {
      int x1 = v[0], y1 = v[1];
      int x2 = v[2], y2 = v[3];
      mp[{x1, y1}]++;
      mp[{x2, y2}]++;
      mp[{x1, y2}]--;
      mp[{x2, y1}]--;
    }

    int cnt = 0;
    for (auto& [k, v] : mp)
      if (v) {
        if (abs(v) != 1) return false;
        cnt++;
      }
    return cnt == 4;
  }
};
// @lc code=end
