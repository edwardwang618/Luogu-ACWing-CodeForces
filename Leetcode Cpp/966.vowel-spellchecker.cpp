/*
 * @lc app=leetcode id=966 lang=cpp
 *
 * [966] Vowel Spellchecker
 */

// @lc code=start
class Solution {
 public:
  vector<string> spellchecker(vector<string>& wordlist,
                              vector<string>& queries) {
    unordered_set<string> set;
    unordered_map<string, string> mp2, mp3;
    for (auto& s : wordlist) {
      auto t = s;
      if (!set.count(s)) set.insert(s);
      auto ss = trans1(s);
      if (!mp2.count(ss)) mp2[ss] = t;
      ss = trans2(s);
      if (!mp3.count(ss)) mp3[ss] = t;
    }

    vector<string> res;
    for (auto& s : queries) {
      if (set.count(s)) {
        res.push_back(s);
        continue;
      }
      auto ss = trans1(s);
      if (mp2.count(ss)) {
        res.push_back(mp2[ss]);
        continue;
      }
      ss = trans2(s);
      if (mp3.count(ss)) {
        res.push_back(mp3[ss]);
        continue;
      }
      res.push_back("");
    }

    return res;
  }

  string trans1(string& s) {
    for (char& ch : s) ch = tolower(ch);
    return s;
  }

  string trans2(string& s) {
    for (char& ch : s)
      if (ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ch = 'a';

    return s;
  }
};
// @lc code=end
