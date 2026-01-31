/*
 * @lc app=leetcode id=2876 lang=cpp
 *
 * [2876] Count Visited Nodes in a Directed Graph
 */

// @lc code=start
class Solution {
public:
  vector<int> countVisitedNodes(vector<int> &es) {
    int n = es.size();
    vector<int> res(n), dfn(n);
    auto dfs = [&](this auto &&dfs, int u, int time) -> int {
      if (res[u]) return 0;
      if (dfn[u]) {
        res[u] = time - dfn[u];
        return dfn[u];
      }
      dfn[u] = time;
      int cycle_start_time = dfs(es[u], time + 1);
      if (!cycle_start_time) {
        res[u] = res[es[u]] + 1;
        return 0;
      }
      res[u] = res[es[u]] + (cycle_start_time > time);
      return cycle_start_time;
    };

    for (int i = 0; i < n; i++)
      if (!res[i])
        dfs(i, 1);

    return res;
  }
};
// @lc code=end
