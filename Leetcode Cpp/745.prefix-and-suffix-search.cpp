/*
 * @lc app=leetcode id=745 lang=cpp
 *
 * [745] Prefix and Suffix Search
 */

// @lc code=start
class WordFilter {
 public:
  struct Node {
    int w;
    Node* ne[27];
    Node() : w(-1) { fill(ne, ne + 27, nullptr); }
  };

  Node* root;

  void insert(string& s, int id) {
    auto p = root;
    for (auto ch : s) {
      int c = ch != '#' ? ch - 'a' : 26;
      if (!p->ne[c]) p->ne[c] = new Node();
      p = p->ne[c];
      p->w = id;
    }
  }

  WordFilter(vector<string>& words) {
    root = new Node();
    for (int i = 0; i < words.size(); i++) {
      string s = "#" + words[i];
      insert(s, i);
      for (int j = words[i].size() - 1; j >= 0; j--) {
        s = words[i][j] + s;
        insert(s, i);
      }
    }
  }

  int f(string pref, string suff) {
    string s = suff + "#" + pref;
    auto p = root;
    for (auto ch : s) {
      int c = ch != '#' ? ch - 'a' : 26;
      if (!p->ne[c]) return -1;
      p = p->ne[c];
    }

    return p->w;
  }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */
// @lc code=end
