/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

// @lc code=start
class Solution {
public:
  struct Node {
    int ne[26]{};
    bool is_word = false;
  };

  vector<Node> tr;
#define root 0
#define child(p, idx) tr[p].ne[idx]
#define is_word(p) tr[p].is_word

  void add(string &s) {
    int p = root;
    for (char ch : s) {
      int idx = ch - 'a';
      if (!child(p, idx)) {
        child(p, idx) = tr.size();
        tr.emplace_back();
      }
      p = child(p, idx);
    }
    is_word(p) = true;
  }

  string longestWord(vector<string> &ws) {
    tr.emplace_back();
    for (auto &s : ws) add(s);
    string res, s;
    auto dfs = [&](this auto &&dfs, int p) -> void {
      if (s.size() > res.size()) res = s;
      for (int i = 0; i < 26; i++)
        if (child(p, i) && is_word(child(p, i))) {
          s += 'a' + i;
          dfs(child(p, i));
          s.pop_back();
        }
    };
    dfs(root);
    return res;
  }
};
// @lc code=end
