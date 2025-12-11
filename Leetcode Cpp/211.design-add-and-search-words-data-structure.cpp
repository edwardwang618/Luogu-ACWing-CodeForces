/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
public:
  struct Node {
    int son[26];
    bool is_word;
    Node() : son{0}, is_word(false) {}
  };

  vector<Node> pl;

  WordDictionary() { pl.emplace_back(); }

  void addWord(const string &word) {
    int p = 0;
    for (auto &c : word) {
      int idx = c - 'a', ne = pl[p].son[idx];
      if (!ne) {
        pl[p].son[idx] = ne = pl.size();
        pl.emplace_back();
      }
      p = pl[p].son[idx];
    }
    pl[p].is_word = true;
  }

  bool search(const string &word) { return dfs(0, 0, word); }

  bool dfs(int u, int p, const string &s) {
    if (u == s.size())
      return pl[p].is_word;
    if (s[u] != '.') {
      if (pl[p].son[s[u] - 'a'])
        return dfs(u + 1, pl[p].son[s[u] - 'a'], s);
      else
        return false;
    }

    for (int i = 0; i < 26; i++)
      if (pl[p].son[i] && dfs(u + 1, pl[p].son[i], s))
        return true;
    return false;
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
