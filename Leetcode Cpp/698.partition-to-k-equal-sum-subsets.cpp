/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
  bool canPartitionKSubsets(vector<int> &a, int k) {
    static constexpr int N = 16;
    int n = a.size();
    int sum = 0;
    for (int x : a) sum += x;
    if (sum % k) return false;

    sort(a.begin(), a.end(), greater<>{});
    sum /= k;
    if (a[0] > sum) return false;

    vector<int> g(k);
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == sum) g[idx++] = sum;
      else break;
    }
    
    auto dfs = [&](this auto &&dfs, int g_start, int u) -> bool {
      if (u == n) return true;
      for (int i = g_start; i < k; i++) {
        if (g[i] + a[u] > sum) continue;
        if (i && g[i] == g[i - 1]) continue;
        g[i] += a[u];
        if (dfs(g_start, u + 1)) return true;
        g[i] -= a[u];
      }
      return false;
    };

    return dfs(idx, idx);
  }
};
// @lc code=end
