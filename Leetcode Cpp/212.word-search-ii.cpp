/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    Node *son[26];
    bool is_word;
  } * root;
  int d[5] = {-1, 0, 1, 0, -1};

  void insert(string &s) {
    auto p = root;
    for (auto &c : s) {
      int idx = c - 'a';
      if (!p->son[idx]) p->son[idx] = new Node();
      p = p->son[idx];
    }
    p->is_word = true;
  }

  vector<string> findWords(vector<vector<char>> &g, vector<string> &ws) {
    root = new Node();
    for (auto &s : ws) insert(s);
    unordered_set<string> res;

    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++) {
        string s;
        auto p = root;
        dfs(i, j, p, s, res, g);
      }

    return vector<string>(res.begin(), res.end());
  }

  void dfs(int x, int y, Node *p, string &s, unordered_set<string> &res,
           vector<vector<char>> &g) {
    char ch = g[x][y];
    if (!p->son[ch - 'a']) return;
    p = p->son[ch - 'a'];
    s += ch;
    if (p->is_word) res.insert(s);

    g[x][y] = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size() &&
          g[nx][ny]) {
        dfs(nx, ny, p, s, res, g);
      }
    }
    g[x][y] = ch;
    s.pop_back();
  }
};
// @lc code=end
