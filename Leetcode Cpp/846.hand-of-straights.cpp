/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution {
public:
  bool isNStraightHand(vector<int> &a, int sz) {
    int n = a.size();
    if (n % sz) return false;
    map<int, int> mp;
    for (int x : a) mp[x]++;
    for (auto [k, cnt] : mp) {
      if (cnt <= 0) continue;
      for (int i = 1; i < sz; i++) {
        int &c = mp[k + i];
        if (c < cnt) return false;
        c -= cnt;
      }
    }
    return true;
  }
};
// @lc code=end
