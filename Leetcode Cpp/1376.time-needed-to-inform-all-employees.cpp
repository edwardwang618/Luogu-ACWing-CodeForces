/*
 * @lc app=leetcode id=1376 lang=cpp
 *
 * [1376] Time Needed to Inform All Employees
 */

// @lc code=start
class Solution {
 public:
  vector<int> h, e, ne, w;
  int idx;

  void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
  }

  int numOfMinutes(int n, int headID, vector<int>& manager,
                   vector<int>& informTime) {
    h = vector<int>(n, -1);
    e = vector<int>(n - 1);
    ne = vector<int>(n - 1);
    w = vector<int>(n - 1);
    idx = 0;

    for (int i = 0; i < n; i++)
      if (~manager[i]) add(manager[i], i, informTime[manager[i]]);

    return dfs(headID);
  }

  int dfs(int u) {
    int t = 0;
    for (int i = h[u]; ~i; i = ne[i]) t = max(t, w[i] + dfs(e[i]));

    return t;
  }
};
// @lc code=end
