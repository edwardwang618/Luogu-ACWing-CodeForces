/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
    int ind[n];
    memset(ind, 0, sizeof ind);
    for (int i = 0; i < n; i++) {
      if (~left[i]) ind[left[i]]++;
      if (~right[i]) ind[right[i]]++;
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
      if (!ind[i])
        if (root == -1)
          root = i;
        else
          return false;
    }

    if (root == -1) return false;

    vector<bool> vis(n, false);
    int cnt = 0;
    return dfs(root, vis, left, right, cnt) && cnt == n;
  }

  bool dfs(int u, vector<bool>& vis, vector<int>& left, vector<int>& right,
           int& cnt) {
    vis[u] = true;
    cnt++;
    if (~left[u] && (vis[left[u]] || !dfs(left[u], vis, left, right, cnt)))
      return false;
    if (~right[u] && (vis[right[u]] || !dfs(right[u], vis, left, right, cnt)))
      return false;
    return true;
  }
};
// @lc code=end
