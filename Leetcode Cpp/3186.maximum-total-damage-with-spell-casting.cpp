/*
 * @lc app=leetcode id=3186 lang=cpp
 *
 * [3186] Maximum Total Damage With Spell Casting
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  using PLI = pair<ll, int>;
#define x first
#define y second
  ll maximumTotalDamage(vector<int>& ps) {
    map<ll, int> mp;
    for (int x : ps) mp[(ll)x]++;

    int n = mp.size();
    vector<PLI> v{{0, 0}};
    v.insert(v.end(), mp.begin(), mp.end());
    vector<ll> f(n + 1);
    f[1] = v[1].x * v[1].y;
    if (n <= 1) return f[1];
    if (v[1].x >= v[2].x - 2)
      f[2] = max(v[1].x * v[1].y, v[2].x * v[2].y);
    else
      f[2] = v[1].x * v[1].y + v[2].x * v[2].y;
    for (int i = 3; i <= n; i++) {
      f[i] = f[i - 1];
      ll x1 = v[i].x, x2 = v[i - 1].x, x3 = v[i - 2].x;
      if (x2 < x1 - 2)
        f[i] = max(f[i], f[i - 1] + x1 * v[i].y);
      else if (x2 == x1 - 2 || x2 == x1 - 1 && x3 < x2 - 1)
        f[i] = max(f[i], f[i - 2] + x1 * v[i].y);
      else
        f[i] = max(f[i], f[i - 3] + x1 * v[i].y);
    }

    return f[n];
  }
};
// @lc code=end
