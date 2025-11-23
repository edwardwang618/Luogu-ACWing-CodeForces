/*
 * @lc app=leetcode id=964 lang=cpp
 *
 * [964] Least Operators to Express Number
 */

// @lc code=start
class Solution {
 public:
  int leastOpsExpressTarget(int x, int target) {
    unordered_map<string, int> mp;
    return dfs(target, 0, x, mp) - 1;
  }

  int dfs(int target, int i, int x, unordered_map<string, int>& mp) {
    string s = to_string(target) + "#" + to_string(i);
    if (mp.count(s)) return mp[s];
    int cost = i ? i : 2;
    if (!target) return mp[s] = 0;
    if (target == 1) return mp[s] = cost;

    int d = target / x, r = target % x;
    if (!r) return mp[s] = dfs(d, i + 1, x, mp);
    return mp[s] = min(dfs(d, i + 1, x, mp) + r * cost,
                       dfs(d + 1, i + 1, x, mp) + (x - r) * cost);
  }
};
// @lc code=end
