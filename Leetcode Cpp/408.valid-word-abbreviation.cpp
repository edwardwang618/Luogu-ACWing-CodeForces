/*
 * @lc app=leetcode id=408 lang=cpp
 *
 * [408] Valid Word Abbreviation
 */

// @lc code=start
class Solution {
 public:
  bool validWordAbbreviation(string w, string a) {
    int i, j;
    for (i = 0, j = 0; i < w.size() && j < a.size();) {
      if (w[i] == a[j]) {
        i++, j++;
        continue;
      }

      if (isalpha(a[j])) return false;
      if (a[j] == '0') return false;
      int k = j;
      while (k < a.size() && isdigit(a[k])) k++;
      int x = stoi(a.substr(j, k - j));
      i += x;
      j = k;
    }

    return i == w.size() && j == a.size();
  }
};
// @lc code=end
