/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 */

// @lc code=start
class Solution {
public:
  int countRangeSum(vector<int> &a, int lo, int hi) {
    int n = a.size();
    using ll = long long;
    vector<ll> p(n + 1);
    for (int i = 0; i < n; i++)
      p[i + 1] = p[i] + a[i];
    auto q = p;
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());
    auto id = [&](ll x) {
      return lower_bound(q.begin(), q.end(), x) - q.begin() + 1;
    };
    int m = q.size();
    vector<int> tr(m + 1);
    auto lowbit = [](int x) { return x & -x; };
    auto add = [&](int k, int x) {
      for (; k <= m; k += lowbit(k))
        tr[k] += x;
    };
    auto sum = [&](int k) {
      int s = 0;
      for (; k; k -= lowbit(k))
        s += tr[k];
      return s;
    };

    int res = 0;
    for (int i = 0; i <= n; i++) {
      ll l = p[i] - hi, r = p[i] - lo;
      int L = lower_bound(q.begin(), q.end(), l) - q.begin() + 1;
      int R = upper_bound(q.begin(), q.end(), r) - q.begin() + 1;
      res += sum(R - 1) - sum(L - 1);
      add(id(p[i]), 1);
    }
    return res;
  }
};
// @lc code=end
