/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
public:
  struct Node {
    int son[26];
    bool is_word;
    Node() : son{0}, is_word(false) {}
  };

  vector<Node> pool;

  Trie() { pool.emplace_back(); }

  void insert(const string &word) {
    int p = 0;
    for (auto &c : word) {
      int idx = c - 'a', ne = pool[p].son[idx];
      if (!ne) {
        pool[p].son[idx] = ne = pool.size();
        pool.emplace_back();
      }
      p = ne;
    }
    pool[p].is_word = true;
  }

  bool search(const string &word) {
    int p = 0;
    for (auto &c : word) {
      int idx = c - 'a';
      if (!pool[p].son[idx])
        return false;
      p = pool[p].son[idx];
    }
    return pool[p].is_word;
  }

  bool startsWith(const string &prefix) {
    int p = 0;
    for (auto &c : prefix) {
      int idx = c - 'a';
      if (!pool[p].son[idx])
        return false;
      p = pool[p].son[idx];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
