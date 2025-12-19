/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
public:
  // vector<int> eventualSafeNodes(vector<vector<int>> &g) {
  //   int n = g.size();
  //   vector<int> res, vis(n);
  //   for (int i = 0; i < n; i++)
  //     if (dfs(i, vis, g)) res.push_back(i);
  //   return res;
  // }

  // static bool dfs(int u, auto& vis, auto& g) {
  //   if (vis[u]) return vis[u] == 2;
  //   vis[u] = 1;
  //   for (int ne : g[u]) {
  //     if (vis[ne] == 2) continue;
  //     if (vis[ne] == 1 || !dfs(ne, vis, g)) return false;
  //   }
  //   vis[u] = 2;
  //   return true;
  // }

  vector<int> eventualSafeNodes(vector<vector<int>> &g) {
    int n = g.size();
    vector<vector<int>> gg(n);
    vector<int> ind(n);
    for (int i = 0; i < n; i++)
      for (int x : g[i]) {
        gg[x].push_back(i);
        ind[i]++;
      }
    g = move(gg);
    vector<int> res;
    vector<bool> safe(n);
    queue<int> q;
    for (int i = 0; i < n; i++) if (!ind[i]) q.push(i);
    while (q.size()) {
      auto t = q.front(); q.pop();
      safe[t] = true;
      for (int ne : g[t]) {
        if (!--ind[ne]) q.push(ne);
      }
    }
    for (int i = 0; i < n; i++) if (safe[i]) res.push_back(i);
    return res;
  }
};
// @lc code=end
