/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  int divide(int x, int y) {
    int sign = 1;
    if (x < 0 && y > 0 || x > 0 && y < 0) sign = -1;
    vector<ll> v;
    ll a = abs(x), b = abs(y);
    for (ll i = b; i <= a; i += i) v.push_back(i);
    ll res = 0;
    for (int i = v.size() - 1; i >= 0; i--)
      if (a >= v[i]) a -= v[i], res |= 1ll << i;
    res *= sign;
    if (res < INT_MIN || res > INT_MAX) return INT_MAX;
    return res;
  }
};
// @lc code=end
