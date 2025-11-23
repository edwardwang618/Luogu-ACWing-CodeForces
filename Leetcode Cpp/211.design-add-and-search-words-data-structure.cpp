/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
 public:
  struct Node {
    Node *son[26];
    bool is_word;
  } *root;

  WordDictionary() {
    root = new Node();
  }

  void addWord(string word) {
    auto cur = root;
    for (auto &c : word) {
      int idx = c - 'a';
      if (!cur->son[idx]) cur->son[idx] = new Node();
      cur = cur->son[idx];
    }
    cur->is_word = true;
  }

  bool search(string word) {
    return dfs(0, root, word);
  }

  bool dfs(int u, Node *cur, string &s) {
    if (u == s.size()) return cur->is_word;
    if (s[u] != '.')
      if (cur->son[s[u] - 'a']) 
        return dfs(u + 1, cur->son[s[u] - 'a'], s);
      else return false;
    
    for (int i = 0; i < 26; i++)
      if (cur->son[i] && dfs(u + 1, cur->son[i], s))
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
