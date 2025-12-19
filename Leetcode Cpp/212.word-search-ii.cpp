/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
public:
  struct Node {
    int son[26];
    bool is_word;
    Node() : son{0}, is_word(false) {}
  };
  vector<Node> tr;

  void insert(string &s) {
    int p = 0;
    for (auto &c : s) {
      int idx = c - 'a', ne = tr[p].son[idx];
      if (!ne) {
        tr[p].son[idx] = ne = tr.size();
        tr.emplace_back();
      }
      p = ne;
    }
    tr[p].is_word = true;
  }

  vector<string> findWords(vector<vector<char>> &g, vector<string> &ws) {
    tr.emplace_back();
    for (auto &s : ws)
      insert(s);
    unordered_set<string> res;

    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++) {
        string s;
        dfs(i, j, 0, s, res, g);
      }

    return vector<string>(res.begin(), res.end());
  }

  void dfs(int x, int y, int p, string &s, auto &res, auto &g) {
    static int d[] = {1, 0, -1, 0, 1};
    char ch = g[x][y];
    int ne = tr[p].son[ch - 'a'];
    if (!ne)
      return;
    p = ne;
    s += ch;
    if (tr[p].is_word)
      res.insert(s);

    g[x][y] = 0;
    for (int i = 0; i < 4; i++) {
      int nx = x + d[i], ny = y + d[i + 1];
      if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size() && g[nx][ny])
        dfs(nx, ny, p, s, res, g);
    }
    g[x][y] = ch;
    s.pop_back();
  }
};
// @lc code=end
