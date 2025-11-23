/*
 * @lc app=leetcode id=616 lang=cpp
 *
 * [616] Add Bold Tag in String
 */

// @lc code=start
class Solution {
 public:
#define N 40000
  int tr[N][62], ne[N], idx;
  int len[N];
  unordered_map<char, int> mp;

  void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = mp[s[i]];
      if (!tr[p][c]) tr[p][c] = ++idx;
      p = tr[p][c];
    }
    len[p] = s.size();
  }

  void build() {
    queue<int> q;
    for (int i = 0; i < 62; i++)
      if (tr[0][i]) q.push(tr[0][i]);

    while (q.size()) {
      auto t = q.front(); q.pop();
      for (int i = 0; i < 62; i++) {
        int& p = tr[t][i];
        if (p) ne[p] = tr[ne[t]][i], q.push(p);
        else p = tr[ne[t]][i];
      }
    }
  }

  void query(string &s, vector<bool>& b, vector<string>& words) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      p = tr[p][mp[s[i]]];
      if (len[p])
        for (int j = 0; j < len[p]; j++)
          if (!b[i - j]) b[i - j] = true;
          else break;
    }
  }

  string addBoldTag(string s, vector<string>& words) {
    int cnt = 0;
    for (char ch = 'A'; ch <= 'Z'; ch++) mp[ch] = cnt++;
    for (char ch = 'a'; ch <= 'z'; ch++) mp[ch] = cnt++;
    for (char ch = '0'; ch <= '9'; ch++) mp[ch] = cnt++;
    for (int i = 0; i < words.size(); i++) insert(words[i]);
    build();
    vector<bool> b(s.size());
    query(s, b, words);

    string res;
    for (int i = 0; i < s.size(); i++)
      if (!b[i]) res += s[i];
      else {
        res += "<b>";
        int j = i;
        while (j < s.size() && b[j]) res += s[j++];
        i = j - 1;
        res += "</b>";
      }

    return res;
  }
};
// @lc code=end
