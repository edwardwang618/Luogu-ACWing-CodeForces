/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
class Solution {
 public:
  using ll = long long;
  using PLL = pair<ll, ll>;
  int rangeSum(vector<int>& a, int n, int l, int r) {
    constexpr ll MOD = 1e9 + 7;
    vector<ll> s(n + 1), ss(n + 1);
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + a[i - 1];
      ss[i] = ss[i - 1] + s[i];
    }

    auto get_sum_and_cnt = [&](int x) -> PLL {
      ll sum = 0, cnt = 0;
      for (int i = 1, j = 0; i <= n; i++) {
        while (j < i && s[i] - s[j] >= x) j++;
        if (j < i) {
          cnt += i - j;
          sum += (i - j) * s[i] - (ss[i - 1] - (j ? ss[j - 1] : 0));
        }
      }
      return {sum, cnt};
    };
    auto get_kth = [&](int k) -> int {
      int l = 0, r = s[n];
      while (l < r) {
        int mid = l + (r - l + 1 >> 1);
        auto [sum, cnt] = get_sum_and_cnt(mid);
        if (cnt < k)
          l = mid;
        else
          r = mid - 1;
      }
      return l;
    };

    auto f = [&](int k) -> ll {
      auto x = get_kth(k);
      auto [sum, cnt] = get_sum_and_cnt(x);
      return sum + (k - cnt) * x;
    };
    return (f(r) - f(l - 1)) % MOD;
  }
};
// @lc code=end
