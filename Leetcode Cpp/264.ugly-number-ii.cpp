/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> a(n);
    a[0] = 1;
    int idx = 1;
    for (int two = 0, three = 0, five = 0; idx < n;) {
      int ne = min(min(a[two] * 2, a[three] * 3), a[five] * 5);
      a[idx++] = ne;
      if (ne == a[two] * 2) two++;
      if (ne == a[three] * 3) three++;
      if (ne == a[five] * 5) five++;
    }

    return a.back();
  }
};
// @lc code=end
