/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start
class Solution {
public:
  int longestMountain(vector<int> &a) {
    int l = 0, r = 0, n = a.size();
    int res = 0;
    while (l < n) {
      while (l + 1 < n && a[l] == a[l + 1]) l++;
      if (l == n - 1) break;
      r = l + 1;
      bool up = false, down = false;
      while (r < n && a[r - 1] < a[r]) {
        r++;
        up = true;
      }
      while (r < n && a[r - 1] > a[r]) {
        r++;
        down = true;
      }
      if (up && down) res = max(res, r - l);
      l = r = r - 1;
    }
    return res;
  }
};
// @lc code=end
