/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;

    for (int i = 0; i < flowerbed.size(); i++) {
      if (flowerbed[i] == 1) continue;
      bool canPlace = true;
      if (i < flowerbed.size() - 1 && flowerbed[i + 1] == 1) canPlace = false;
      if (i > 0 && flowerbed[i - 1] == 1) canPlace = false;
      if (canPlace) {
        flowerbed[i] = 1;
        n--;
        if (n == 0) return true;
      }
    }

    return false;
  }
};
// @lc code=end
