/*
 * @lc app=leetcode id=3331 lang=cpp
 *
 * [3331] Find Subtree Sizes After Changes
 */

// @lc code=start
class Solution {
public:
  vector<int> findSubtreeSizes(vector<int> &pa, string &s) {
    int n = pa.size();
    vector<int> h(n, -1), e(n - 1), ne(n - 1);
    int idx = 0;
    auto add = [&](int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; };
    for (int i = 1; i < n; i++) add(pa[i], i);
    vector<int> last(26, -1);
    auto dfs = [&](this auto &&dfs, int u) -> void {
      int idx = s[u] - 'a', old = last[idx];
      if (~last[idx]) pa[u] = last[idx];
      last[idx] = u;
      for (int i = h[u]; ~i; i = ne[i]) dfs(e[i]);
      last[idx] = old;
    };
    dfs(0);
    fill(h.begin(), h.end(), -1);
    idx = 0;
    for (int i = 0; i < n; i++)
      if (~pa[i]) add(pa[i], i);
    vector<int> res(n);
    auto dfs2 = [&](this auto &&dfs2, int u) -> int {
      int cnt = 1;
      for (int i = h[u]; ~i; i = ne[i]) cnt += dfs2(e[i]);
      return res[u] = cnt;
    };
    dfs2(0);
    return res;
  }
};
// @lc code=end
