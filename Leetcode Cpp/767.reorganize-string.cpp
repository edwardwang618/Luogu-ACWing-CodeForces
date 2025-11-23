/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution {
 public:
  string reorganizeString(string s) {
    int n = s.size();
    vector<int> cnt(26, 0);
    for (char c : s) cnt[c - 'a']++;
    if (*max_element(cnt.begin(), cnt.end()) > (n + 1) / 2) return "";

    vector<pair<int, char>> ls;
    for (int i = 0; i < 26; ++i)
      if (cnt[i]) ls.push_back({cnt[i], 'a' + i});

    sort(ls.begin(), ls.end(), greater<>());

    string res(n, ' ');
    int idx = 0;
    for (auto &[cnt, c] : ls)
      for (int i = 0; i < cnt; ++i) {
        if (idx >= n) idx = 1;
        res[idx] = c;
        idx += 2;
      }

    return res;
  }
};
// @lc code=end
