using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool hasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    string s1, s2;
    dfs(pRoot1, s1);
    dfs(pRoot2, s2);
    s1 = " " + s1;
    s2 = " " + s2;
    auto ne = build_ne(s2);
    return kmp(s1, s2, ne);
  }

  bool kmp(string &s, string &p, vector<int> &ne) {
    int n = s.size() - 1, m = p.size() - 1;
    if (!m) return false;
    for (int i = 1, j = 0; i <= n; i++) {
      while (j && s[i] != p[j + 1]) j = ne[j];
      if (s[i] == p[j + 1]) j++;
      if (j == m) return true;
    }
    return false;
  }

  vector<int> build_ne(string &s) {
    int n = s.size() - 1;
    vector<int> ne(n + 1);
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && s[i] != s[j + 1]) j = ne[j];
      if (s[i] == s[j + 1]) j++;
      ne[i] = i < n && s[i + 1] != s[j + 1] ? j : ne[j];
    }
    return ne;
  }

  void dfs(TreeNode *x, string &s) {
    if (!x) return;
    s += to_string(x->val) + ',';
    dfs(x->left, s);
    dfs(x->right, s);
  }
};