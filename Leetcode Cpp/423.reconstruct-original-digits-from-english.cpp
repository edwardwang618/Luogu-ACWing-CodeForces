/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start
class Solution {
 public:
  string originalDigits(string s) {
    string ss[] = {"zero", "one", "two",   "three", "four",
                   "five", "six", "seven", "eight", "nine"};
    int num[] = {0, 8, 3, 2, 6, 4, 5, 1, 7, 9};
    unordered_map<char, int> mp;
    map<char, int> mp2;
    for (char c : s) mp[c]++;
    string res;
    for (int x : num) {
      int cnt = INT_MAX;
      for (char c : ss[x]) cnt = min(cnt, mp[c]);
      if (!cnt) continue;
      mp2[x + '0'] = cnt;
      for (char c : ss[x]) mp[c] -= cnt;
    }
    for (auto &[k, v] : mp2) res += string(v, k);
    return res;
  }
};
// @lc code=end
