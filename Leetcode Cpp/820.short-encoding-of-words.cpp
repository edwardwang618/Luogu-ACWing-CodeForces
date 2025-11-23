/*
 * @lc app=leetcode id=820 lang=cpp
 *
 * [820] Short Encoding of Words
 */

// @lc code=start
class Solution {
 public:
  struct Node {
    Node* ne[26];
    bool valid;
    Node() : valid(true) { fill(ne, ne + 26, nullptr); }
  };

  Node* root;
  void insert(string& s, unordered_map<Node*, int>& mp) {
    auto* p = root;
    for (char ch : s) {
      p->valid = false;
      int idx = ch - 'a';
      if (!p->ne[idx]) p->ne[idx] = new Node();
      p = p->ne[idx];
    }

    mp[p] = s.size();
  }

  int minimumLengthEncoding(vector<string>& words) {
    root = new Node();
    unordered_map<Node*, int> mp;
    for (int i = 0; i < words.size(); i++) {
      auto& s = words[i];
      reverse(s.begin(), s.end());
      insert(s, mp);
    }

    int res = 0;
    for (auto& [p, len] : mp)
      if (p->valid) res += len + 1;

    return res;
  }
};
// @lc code=end
