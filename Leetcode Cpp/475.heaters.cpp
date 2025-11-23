/*
 * @lc app=leetcode id=475 lang=cpp
 *
 * [475] Heaters
 */

// @lc code=start
class Solution {
 public:
  int findRadius(vector<int>& houses, vector<int>& heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int l = 0, r = max(heaters[0] - houses[0], houses.back() - heaters[0]);
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (check(mid, houses, heaters)) r = mid;
      else l = mid + 1;
    }

    return l;
  }

  bool check(int len, vector<int>& ho, vector<int>& he) {
    for (int i = 0, j = 0; i < he.size(); i++) {
      if (ho[j] < he[i] - len) return false;
      while (j < ho.size() && abs(ho[j] - he[i]) <= len) j++;
      if (j == ho.size()) return true;
    }

    return false;
  }
};
// @lc code=end
