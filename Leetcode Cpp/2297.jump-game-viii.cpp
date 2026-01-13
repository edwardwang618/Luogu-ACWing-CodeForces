/*
 * @lc app=leetcode id=2297 lang=cpp
 *
 * [2297] Jump Game VIII
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll minCost(vector<int> &a, vector<int> &cs) {
    int n = a.size();
    stack<int> stk1, stk2;
    static constexpr ll INF = 9e18;
    vector<ll> f(n, INF);
    f[n - 1] = 0;
    for (int i = n - 1; i >= 0; i--) {
      while (stk1.size() && a[i] > a[stk1.top()]) stk1.pop();
      if (stk1.size()) {
        int t = stk1.top();
        f[i] = min(f[i], cs[t] + f[t]);
      }
      stk1.push(i);

      while (stk2.size() && a[i] <= a[stk2.top()]) stk2.pop();
      if (stk2.size()) {
        int t = stk2.top();
        f[i] = min(f[i], cs[t] + f[t]);
      }
      stk2.push(i);
    }
    return f[0] != INF ? f[0] : -1;
  }
};
// @lc code=end
