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

#define son(p, idx) tr[p].son[idx]
#define is_word(p) tr[p].is_word

  vector<Node> tr;

  Trie() { tr.emplace_back(); }

  void insert(const string &word) {
    int p = 0;
    for (auto &c : word) {
      int idx = c - 'a', ne = son(p, idx);
      if (!ne) {
        son(p, idx) = ne = tr.size();
        tr.emplace_back();
      }
      p = ne;
    }
    is_word(p) = true;
  }

  bool search(const string &word) {
    int p = 0;
    for (auto &c : word) {
      int idx = c - 'a';
      if (!son(p, idx))
        return false;
      p = son(p, idx);
    }
    return is_word(p);
  }

  bool startsWith(const string &prefix) {
    int p = 0;
    for (auto &c : prefix) {
      int idx = c - 'a';
      if (!son(p, idx))
        return false;
      p = son(p, idx);
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
