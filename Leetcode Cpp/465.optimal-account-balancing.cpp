/*
 * @lc app=leetcode id=465 lang=cpp
 *
 * [465] Optimal Account Balancing
 */

// @lc code=start
class Solution {
 public:
  // int minTransfers(vector<vector<int>>& ts) {
  //   unordered_map<int, int> mp;
  //   for (auto& t : ts) {
  //     mp[t[0]] -= t[2];
  //     mp[t[1]] += t[2];
  //   }

  //   vector<int> a;
  //   for (auto& [k, v] : mp)
  //     if (v) a.push_back(v);
  //   if (a.empty()) return 0;
  //   int n = a.size();
  //   int f[1 << n];
  //   memset(f, 0x3f, sizeof f);
  //   for (int i = 1; i < 1 << n; i++) {
  //     int sum = 0, cnt = 0;
  //     for (int j = 0; j < n; j++)
  //       if (1 << j & i) sum += a[j], cnt++;

  //     if (!sum) {
  //       f[i] = cnt - 1;
  //       for (int j = 1; j < i; j++)
  //         if ((i & j) == j) f[i] = min(f[i], f[j] + f[i - j]);
  //     }
  //   }

  //   return f[(1 << n) - 1];
  // }

  int minTransfers(vector<vector<int>>& ts) {
    unordered_map<int, int> mp;
    for (auto& t : ts) mp[t[0]] -= t[2], mp[t[1]] += t[2];
    vector<int> ds;
    for (auto& [k, v] : mp)
      if (v) ds.push_back(v);
    return dfs(0, ds);
  }

  int dfs(int u, vector<int>& ds) {
    while (u < ds.size() && !ds[u]) u++;
    if (u == ds.size()) return 0;
    int res = 2e9;
    for (int i = u + 1; i < ds.size(); i++)
      if (ds[u] * ds[i] < 0) {
        ds[i] += ds[u];
        res = min(res, 1 + dfs(u + 1, ds));
        ds[i] -= ds[u];
      }
    return res;
  }
};
// @lc code=end
