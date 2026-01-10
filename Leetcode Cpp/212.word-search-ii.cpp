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
    int cnt;
    bool is_word;
    Node() : son{}, cnt{}, is_word{} {}
  };
  vector<Node> tr;

#define root 0
#define son(p, idx) tr[p].son[idx]
#define cnt(p) tr[p].cnt
#define is_word(p) tr[p].is_word

  vector<string> findWords(vector<vector<char>> &g, vector<string> &ws) {
    auto insert = [&](string &s) {
      int p = root;
      for (auto &c : s) {
        int idx = c - 'a', ne = son(p, idx);
        if (!ne) {
          son(p, idx) = ne = tr.size();
          tr.emplace_back();
        }
        cnt(p)++;
        p = ne;
      }
      cnt(p)++;
      is_word(p) = true;
    };
    tr.emplace_back();
    for (auto &s : ws) insert(s);
    vector<string> res;
    string s;    
    static constexpr int d[] = {1, 0, -1, 0, 1};
    auto dfs = [&](this auto &&dfs, int x, int y, int p) -> int {
      char ch = g[x][y];
      int ne = son(p, ch - 'a');
      if (!ne || !cnt(ne)) return 0;
      s += ch;
      int found = 0;
      if (is_word(ne)) {
        res.push_back(s);
        found++;
        is_word(ne) = false;
      }
      g[x][y] = 0;
      for (int i = 0; i < 4; i++) {
        int nx = x + d[i], ny = y + d[i + 1];
        if (0 <= nx && nx < g.size() && 0 <= ny && ny < g[0].size() && g[nx][ny])
          found += dfs(nx, ny, ne);
      }
      g[x][y] = ch;
      s.pop_back();
      cnt(ne) -= found;
      return found;
    };
    for (int i = 0; i < g.size(); i++)
      for (int j = 0; j < g[0].size(); j++)
        dfs(i, j, root);

    return res;
  }
};
// @lc code=end
