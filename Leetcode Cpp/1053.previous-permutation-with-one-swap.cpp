/*
 * @lc app=leetcode id=1053 lang=cpp
 *
 * [1053] Previous Permutation With One Swap
 */

// @lc code=start
class Solution {
 public:
  vector<int> prevPermOpt1(vector<int>& a) {
    for (int i = a.size() - 1; i; i--)
      if (a[i] < a[i - 1]) {
        int j = i;
        while (j < a.size() && a[j] < a[i - 1]) j++;
        j--;
        while (a[j] == a[j - 1]) j--;
        swap(a[i - 1], a[j]);
        break;
      }

    return a;
  }
};
// @lc code=end
