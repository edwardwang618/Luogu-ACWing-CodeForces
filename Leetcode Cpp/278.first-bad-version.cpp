/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  // int firstBadVersion(int n) {
  //   int l = 1, r = n;
  //   while (l < r) {
  //     int mid = l + (r - l >> 1);
  //     if (isBadVersion(mid)) r = mid;
  //     else l = mid + 1;
  //   }
  //   return l;
  // }

  int firstBadVersion(int n) {
    int x = 0, p = 1;
    while (p) {
      if (x <= n - p && !isBadVersion(x + p)) {
        x += p;
        p <<= 1;
      } else
        p >>= 1;
    }
    return x + 1;
  }
};
// @lc code=end
