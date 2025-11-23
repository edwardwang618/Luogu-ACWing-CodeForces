/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
 public:
  int findInMountainArray(int t, MountainArray &A) {
    int n = A.length();
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (A.get(mid) > A.get(mid + 1)) r = mid;
      else l = mid + 1;
    }

    int top = l;
    l = 0, r = top;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (A.get(mid) >= t) r = mid;
      else l = mid + 1;
    }

    if (A.get(l) == t) return l;
    l = top + 1, r = n - 1;
    while (l < r) {
      int mid = l + (r - l >> 1);
      if (A.get(mid) <= t) r = mid;
      else l = mid + 1;
    }
    if (A.get(l) == t) return l;
    return -1;
  }
};
// @lc code=end
