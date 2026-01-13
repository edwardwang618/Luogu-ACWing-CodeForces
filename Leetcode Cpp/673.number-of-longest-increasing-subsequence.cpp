/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
  int findNumberOfLIS(vector<int> &a) {
    int n = a.size();
    auto b = a;
    sort(b.begin(), b.end());
    unordered_map<int, int> mp;
    int idx = 1;
    for (int x : b)
      if (mp.emplace(x, idx).second)
        idx++;
    for (int &x : a)
      x = mp[x];

    using PII = pair<int, int>;
    n = idx - 1;
    vector<PII> tr(n + 1);
    auto lowbit = [](int x) { return x & -x; };
    auto merge = [&](PII& p1, const PII& p2) {
      if (p1.first < p2.first) p1 = p2;
      else if (p1.first == p2.first) p1 = {p1.first, p1.second + p2.second};
    };
    auto update = [&](int x, const PII& p) {
      for (; x <= n; x += lowbit(x)) merge(tr[x], p);
    };
    auto sum = [&](int x) {
      PII res = {0, 0};
      for (; x; x -= lowbit(x)) merge(res, tr[x]);
      return res;
    };

    int res = 0, max_len = 0;
    for (int x : a) {
      auto [len, cnt] = sum(x - 1);
      len++;
      if (!cnt) cnt = 1;

      if (len > max_len) {
        max_len = len;
        res = cnt;
      } else if (len == max_len) res += cnt;

      update(x, {len, cnt});
    }

    return res;
  }
};
// @lc code=end
