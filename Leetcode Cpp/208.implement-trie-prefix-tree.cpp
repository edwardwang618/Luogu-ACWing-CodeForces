/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
 public:
  struct Node {
    Node *son[26];
    bool is_word;
  } *root;

  Trie() {
    root = new Node();
  }

  void insert(string word) {
    auto cur = root;
    for (auto &c : word) {
      int idx = c - 'a';
      if (!cur->son[idx]) cur->son[idx] = new Node();
      cur = cur->son[idx]; 
    }
    cur->is_word = true;
  }

  bool search(string word) {
    auto cur = root;
    for (auto &c : word) {
      int idx = c - 'a';
      if (!cur->son[idx]) return false;
      cur = cur->son[idx]; 
    }
    return cur->is_word;
  }

  bool startsWith(string prefix) {
    auto cur = root;
    for (auto &c : prefix) {
      int idx = c - 'a';
      if (!cur->son[idx]) return false;
      cur = cur->son[idx]; 
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
