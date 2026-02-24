/*
 * @lc app=leetcode id=1858 lang=cpp
 *
 * [1858] Longest Word With All Prefixes
 */

// @lc code=start
class Solution {
public:
  struct Node {
    int ne[26]{};
    int idx = -1;
  };
#define child(p, idx) tr[p].ne[idx]
#define idx(p) tr[p].idx

  vector<Node> tr;
  static constexpr int root = 0;

  int new_node() {
    int n = tr.size();
    tr.emplace_back();
    return n;
  }

  void add(const string& s, int i) {
    int p = root;
    for (char ch : s) {
      int idx = ch - 'a';
      if (!child(p, idx)) child(p, idx) = new_node();
      p = child(p, idx);
    }
    idx(p) = i;
  }

  string longestWord(vector<string> &ws) {
    new_node();
    for (int i = 0; i < ws.size(); i++) add(ws[i], i);
    int res = -1;
    auto dfs = [&](this auto &&dfs, int p) -> void {
      if (~idx(p) && (!~res || ws[idx(p)].size() > ws[res].size())) res = idx(p);
      for (int i = 0; i < 26; i++)
        if (child(p, i) && ~idx(child(p, i)))
          dfs(child(p, i));
    };
    dfs(root);
    return ~res ? ws[res] : "";
  }
};
// @lc code=end
