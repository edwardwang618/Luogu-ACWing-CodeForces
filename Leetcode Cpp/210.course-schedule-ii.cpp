/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
 public:
  // vector<int> findOrder(int n, vector<vector<int>> &pre) {
  //   int ind[n];
  //   fill(ind, ind + n, 0);
  //   unordered_map<int, vector<int>> g;
  //   for (auto &e : pre) {
  //     int a = e[0], b = e[1];
  //     g[b].push_back(a);
  //     ind[a]++;
  //   }

  //   queue<int> q;
  //   for (int i = 0; i < n; i++)
  //     if (!ind[i]) q.push(i);

  //   vector<int> res;
  //   while (q.size()) {
  //     int t = q.front(); q.pop();
  //     res.push_back(t);
  //     for (auto &x : g[t])
  //       if (!--ind[x]) q.push(x);
  //   }

  //   if (res.size() < n) return {};
  //   return res;
  // }

  vector<int> findOrder(int n, vector<vector<int>>& pre) {
    unordered_map<int, vector<int>> g;
    for (auto& e : pre) {
      int a = e[0], b = e[1];
      g[b].push_back(a);
    }

    vector<int> res, vis(n, -1);
    for (int i = 0; i < n; i++)
      if (!~vis[i] && !dfs(i, g, vis, res)) return {};
    if (res.size() < n) return {};
    reverse(res.begin(), res.end());
    return res;
  }

  bool dfs(int u, auto& g, vector<int>& vis, vector<int>& res) {
    vis[u] = 0;
    for (int ne : g[u])
      if (!vis[ne])
        return false;
      else if (!~vis[ne] && !dfs(ne, g, vis, res))
        return false;
    vis[u] = 1;
    res.push_back(u);
    return true;
  }
};
// @lc code=end
