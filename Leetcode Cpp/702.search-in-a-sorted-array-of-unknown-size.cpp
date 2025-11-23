/*
 * @lc app=leetcode id=702 lang=cpp
 *
 * [702] Search in a Sorted Array of Unknown Size
 */

// @lc code=start
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
 public:
  int search(const ArrayReader& reader, int target) {
    int l = 0, r = 1;
    while (reader.get(r) < target) {
      l = r;
      r <<= 1;
    }

    while (l < r) {
      int m = l + (r - l + 1 >> 1);
      if (reader.get(m) <= target)
        l = m;
      else
        r = m - 1;
    }
    return reader.get(l) == target ? l : -1;
  }
};
// @lc code=end
