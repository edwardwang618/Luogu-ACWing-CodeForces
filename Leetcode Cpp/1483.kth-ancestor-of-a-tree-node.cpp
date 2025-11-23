/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor {
 public:
  vector<vector<int>> f;

  TreeAncestor(int n, vector<int> &p) {
    int m = (int)log2(n) + 1;
    f = vector<vector<int>>(n, vector<int>(m, -1));
    for (int i = 0; i < p.size(); i++) f[i][0] = p[i];

    for (int j = 1; j < m; j++)
      for (int i = 0; i < n; i++)
        if (~f[i][j - 1]) f[i][j] = f[f[i][j - 1]][j - 1];
  }

  int getKthAncestor(int node, int k) {
    for (int i = 0; 1 << i <= k; i++)
      if (k & 1 << i) {
        if (f[node][i] == -1) return -1;
        node = f[node][i];
      }
    return node;
  }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end
