/*
 * @lc app=leetcode id=2791 lang=cpp
 *
 * [2791] Count Paths That Can Form a Palindrome in a Tree
 */

// @lc code=start
class Solution {
public:
  using ll = long long;
  ll countPalindromePaths(vector<int> &pa, string &s) {
    int n = pa.size();
    vector<int> h(n, -1), e(n - 1), ne(n - 1), w(n - 1);
    int idx = 0;
    auto add = [&](int a, int b, int ch) {
      e[idx] = b, ne[idx] = h[a], w[idx] = ch, h[a] = idx++;
    };
    for (int i = 1; i < n; i++) {
      int bit = 1 << s[i] - 'a';
      add(pa[i], i, bit);
    }
    vector<int> mask(n);
    auto dfs = [&](this auto &&dfs, int u) -> void {
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], bit = w[i];
        mask[v] = mask[u] ^ bit;
        dfs(v);
      }
    };
    dfs(0);

    unordered_map<int, ll> mp;
    ll res = 0;
    for (int i = 0; i < n; i++) {
      int m = mask[i];
      if (auto it = mp.find(m); it != mp.end()) res += it->second;
      for (int k = 0; k < 26; k++) {
        int t = m ^ (1 << k);
        if (auto it = mp.find(t); it != mp.end()) res += it->second;
      }
      ++mp[m];
    }
    return res;
  }
};
// @lc code=end
