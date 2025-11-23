/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    Node* ne[26];
    int cnt;
    Node() : cnt(0) { fill(ne, ne + 26, nullptr); }
  };

  Node* root;

  void insert(string& s) {
    auto p = root;
    for (int i = 0; i < s.size(); i++) {
      int id = s[i] - 'a';
      if (!p->ne[id]) p->ne[id] = new Node();
      p = p->ne[id];
      p->cnt++;
    }
  }

  vector<int> sumPrefixScores(vector<string>& words) {
    root = new Node();
    for (auto& s : words) insert(s);
    vector<int> res;
    for (auto& s : words) {
      auto p = root;
      int c = 0;
      for (int i = 0; i < s.size(); i++) {
        p = p->ne[s[i] - 'a'];
        c += p->cnt;
      }

      res.push_back(c);
    }

    return res;
  }
};
// @lc code=end
