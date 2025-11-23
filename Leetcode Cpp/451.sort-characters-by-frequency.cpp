/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */

// @lc code=start
class Solution {
 public:
#define x first
#define y second
  string frequencySort(string s) {
    unordered_map<char, int> mp;
    for (char ch : s) mp[ch]++;
    vector<pair<char, int>> v(mp.begin(), mp.end());
    sort(v.begin(), v.end(), [&](auto& p1, auto& p2) {
      if (p1.y != p2.y) return p1.y > p2.y;
      return p1.x < p1.x;
    });
    s.clear();
    for (auto& p : v) s += string(p.y, p.x);
    return s;
  }
};
// @lc code=end
