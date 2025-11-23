/*
 * @lc app=leetcode id=1804 lang=cpp
 *
 * [1804] Implement Trie II (Prefix Tree)
 */

// @lc code=start
class Trie {
 public:
  struct Node {
    Node* ne[26];
    int cnt, path_cnt;
    Node() : cnt(0), path_cnt(0) { fill(ne, ne + 26, nullptr); }
  };

  Node* root;

  Trie() : root(new Node()) {}

  void insert(string s) {
    auto p = root;
    for (int i = 0, idx; i < s.size(); i++) {
      idx = s[i] - 'a';
      if (!p->ne[idx]) p->ne[idx] = new Node();
      p = p->ne[idx];
      p->path_cnt++;
    }

    p->cnt++;
  }

  int countWordsEqualTo(string s) {
    auto p = root;
    for (int i = 0, idx; i < s.size(); i++) {
      idx = s[i] - 'a';
      if (!p->ne[idx]) return 0;
      p = p->ne[idx];
    }

    return p->cnt;
  }

  int countWordsStartingWith(string s) {
    auto p = root;
    for (int i = 0, idx; i < s.size(); i++) {
      idx = s[i] - 'a';
      if (!p->ne[idx]) return 0;
      p = p->ne[idx];
    }

    return p->path_cnt;
  }

  void erase(string s) {
    auto p = root;
    for (int i = 0, idx; i < s.size(); i++) {
      idx = s[i] - 'a';
      p = p->ne[idx];
      p->path_cnt--;
    }

    p->cnt--;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
// @lc code=end
