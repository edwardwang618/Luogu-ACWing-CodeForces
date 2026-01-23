/*
 * @lc app=leetcode id=425 lang=cpp
 *
 * [425] Word Squares
 */

// @lc code=start
class Solution {
public:
  struct Node {
    int child[26]{};
    vector<int> words;
  };
  vector<Node> tr;

#define root 0
#define child(p, idx) tr[p].child[idx]
#define words(p) tr[p].words
  int new_node() {
    int n = tr.size();
    tr.emplace_back();
    return n;
  }

  void insert(string& s, int i) {
    int p = root;
    for (char ch : s) {
      int idx = ch - 'a';
      if (!child(p, idx)) child(p, idx) = new_node();
      p = child(p, idx);
      words(p).push_back(i);
    }
  }

  vector<int>& search(string& pre) {
    static vector<int> empty;
    int p = root;
    for (char ch : pre) {
      int idx = ch - 'a';
      if (!child(p, idx)) return empty;
      p = child(p, idx);
    }
    return words(p);
  }

  vector<vector<string>> wordSquares(vector<string> &ws) {
    tr.emplace_back();
    int n = ws[0].size();
    for (int i = 0; i < ws.size(); i++)
      insert(ws[i], i);
    vector<vector<string>> res;
    vector<string> sq;

    auto dfs = [&](this auto &&dfs) -> void {
      int row = sq.size();
      if (row == n) {
        res.push_back(sq);
        return;
      }
      string pre;
      for (int i = 0; i < row; i++) pre += sq[i][row];
      for (int idx : search(pre)) {
        sq.push_back(ws[idx]);
        dfs();
        sq.pop_back();
      }
    };

    for (auto &s : ws) {
      sq.push_back(s);
      dfs();
      sq.pop_back();
    }

    return res;
  }
};
// @lc code=end
