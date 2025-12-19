/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

// @lc code=start
class Solution {
public:
  using PII = pair<int, int>;
  using u32 = uint32_t;
  using u64 = uint64_t;
  bool isPathCrossing(string &p) {
    auto cmp = [](const PII& p) {
      int x = p.first, y = p.second;
      return (u64)(u32)x << 32 | (u32)y;
    };
    unordered_set<PII, decltype(cmp)> vis(0, cmp);
    int x = 0, y = 0;
    vis.emplace(0, 0);
    for (char ch : p) {
      switch (ch) {
        case 'N': y++; break;
        case 'E': x++; break;
        case 'S': y--; break;
        case 'W': x--;
      }
      if (!vis.emplace(x, y).second) return true;
    }
    return false;
  }
};
// @lc code=end
