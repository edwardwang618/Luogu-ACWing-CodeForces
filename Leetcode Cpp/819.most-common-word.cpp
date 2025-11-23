/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
 public:
  string mostCommonWord(string s, vector<string>& b) {
    unordered_set<string> st(b.begin(), b.end());
    unordered_map<string, int> cnt;
    string t;
    for (char ch : s)
      if (isalpha(ch)) t += tolower(ch);
      else if (t.size()) {
        if (!st.count(t)) cnt[t]++;
        t.clear();
      }

    if (t.size() && !st.count(t)) cnt[t]++;
    string res;
    for (auto& [k, v] : cnt)
      if (cnt[res] < v) res = k;
    return res;
  }
};
// @lc code=end
