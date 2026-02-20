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
    auto ha = [&](auto &p) {
      using ll = long long;
      return hash<ll>{}(((ll)p.first << 32) | (ll)p.second);
    };
    unordered_map<PII, double, decltype(ha)> mp({}, ha);
    auto dfs = [&](this auto &&dfs, int x, int y) -> double {
      if (x <= 0 && y <= 0) return 0.5;
      if (x <= 0) return 1;
      if (y <= 0) return 0;
      auto [it, ins] = mp.try_emplace({x, y}, 0);
      if (!ins) return it->second;
      return it->second = (dfs(x - 4, y) + dfs(x - 3, y - 1) +
                           dfs(x - 2, y - 2) + dfs(x - 1, y - 3)) /
                          4.0;
    };
    return dfs(n, n);
  }
};
// @lc code=end
