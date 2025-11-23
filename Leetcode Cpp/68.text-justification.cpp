/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
 public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    for (int i = 0; i < words.size(); i++) {
      int len = words[i].size(), j = i + 1;
      while (j < words.size() && len + 1 + words[j].size() <= maxWidth)
        len += 1 + words[j++].size();

      int cnt = j - i;
      string s = words[i];
      if (cnt == 1 || j == words.size()) {
        for (int k = i + 1; k < j; k++) s += " " + words[k];
        s.insert(s.end(), maxWidth - s.size(), ' ');
      } else {
        int len_sp = (maxWidth - len + cnt - 1) / (cnt - 1);
        for (int k = i + 1, l = 0; k < j; k++, l++) {
          s.insert(s.end(), len_sp, ' ');
          if (l < (maxWidth - len + cnt - 1) % (cnt - 1)) s += ' ';
          s += words[k];
        }
      }
      res.push_back(s);
      i = j - 1;
    }

    return res;
  }
};
// @lc code=end
