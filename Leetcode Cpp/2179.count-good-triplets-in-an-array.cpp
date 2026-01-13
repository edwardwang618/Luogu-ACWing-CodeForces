/*
 * @lc app=leetcode id=2179 lang=cpp
 *
 * [2179] Count Good Triplets in an Array
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll goodTriplets(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<int> posb(n);
    for (int i = 0; i < n; i++) posb[b[i]] = i;
    vector<int> tr(n + 1);
    auto lowbit = [](int x) { return x & -x; };
    auto add = [&](int i) {
      i++;
      for (; i <= n; i += lowbit(i)) tr[i]++;
    };
    auto sum = [&](int i) {
      int s = 0;
      i++;
      for (; i; i -= lowbit(i)) s += tr[i];
      return s;
    };

    ll res = 0;
    for (int i = 0; i < n; i++) {
      int p = posb[a[i]];
      ll l = sum(p - 1);
      ll r = (n - 1 - i) - (p - l);
      res += l * r;
      add(p);
    }
    return res;
  }
};
// @lc code=end
