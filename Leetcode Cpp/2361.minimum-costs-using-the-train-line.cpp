/*
 * @lc app=leetcode id=2361 lang=cpp
 *
 * [2361] Minimum Costs Using the Train Line
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  vector<ll> minimumCosts(vector<int>& reg, vector<int>& exp, int cost) {
    int n = reg.size() + 1;
    vector<ll> res(n - 1);
    ll f[n][2];
    f[0][0] = 0;
    f[0][1] = cost;
    for (int i = 1; i < n; i++) {
      f[i][0] = min(f[i - 1][0] + reg[i - 1], f[i - 1][1] + exp[i - 1]);
      f[i][1] = min(f[i - 1][0] + reg[i - 1] + cost, f[i - 1][1] + exp[i - 1]);
      res[i - 1] = min(f[i][0], f[i][1]);
    }
    return res;
  }
};
// @lc code=end
