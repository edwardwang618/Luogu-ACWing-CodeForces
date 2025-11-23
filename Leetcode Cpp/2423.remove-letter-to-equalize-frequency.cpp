/*
 * @lc app=leetcode id=2423 lang=cpp
 *
 * [2423] Remove Letter To Equalize Frequency
 */

// @lc code=start
class Solution {
 public:
  bool equalFrequency(string s) {
    if (s.empty()) return false;
    unordered_map<int, int> mp, freq;
    for (char ch : s) mp[ch]++;
    for (auto &[k, v] : mp) freq[v]++;
    if (freq.size() > 2) return false;
    if (freq.size() == 1) {
      auto &[k, v] = *freq.begin();
      return k == 1 || v == 1;
    }

    if (freq.count(1) && freq[1] == 1) return true;
    for (auto &[k, v] : freq)
      if (v == 1 && freq.count(k - 1)) return true;
    return false;
  }
};
// @lc code=end
