/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 */

// @lc code=start
class Solution {
 public:
  using PII = pair<int, int>;
  double soupServings(int n) {
    if (n >= 4800) return 1;
    n = (n + 24) / 25;
    auto ha = [&](auto& p) {
      return hash<int>()(p.first) ^ hash<int>()(p.second);
    };
    unordered_map<PII, double, decltype(ha)> mp(0, ha);
    return dfs(n, n, mp);
  }

  double dfs(int x, int y, auto& mp) {
    if (x <= 0 && y <= 0) return 0.5;
    if (x <= 0) return 1;
    if (y <= 0) return 0;
    if (mp.count({x, y})) return mp[{x, y}];
    return mp[{x, y}] = (dfs(x - 4, y, mp) + dfs(x - 3, y - 1, mp) +
                         dfs(x - 2, y - 2, mp) + dfs(x - 1, y - 3, mp)) /
                        4.0;
  }
};
// @lc code=end
