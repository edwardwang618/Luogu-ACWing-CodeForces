/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool isSubtree(TreeNode *r1, TreeNode *r2) {
    string s = " ", p = " ";
    dfs(r1, s);
    dfs(r2, p);
    int n = s.size() - 1, m = p.size() - 1;
    auto ne = [&](auto &p) {
      vector<int> ne(p.size());
      for (int i = 2, j = 0; i <= m; i++) {
        while (j && p[i] != p[j + 1])
          j = ne[j];
        if (p[i] == p[j + 1])
          j++;
        ne[i] = j;
      }
      return ne;
    }(p);

    for (int i = 1, j = 0; i <= n; i++) {
      while (j && s[i] != p[j + 1])
        j = ne[j];
      if (s[i] == p[j + 1])
        j++;
      if (j == m)
        return true;
    }
    return false;
  }

  static void dfs(auto p, auto &s) {
    if (!p) {
      s += "#";
      return;
    }

    s += "$" + to_string(p->val);
    dfs(p->left, s);
    dfs(p->right, s);
  }
};
// @lc code=end
