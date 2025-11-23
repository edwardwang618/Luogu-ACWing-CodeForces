/*
 * @lc app=leetcode id=457 lang=cpp
 *
 * [457] Circular Array Loop
 */

// @lc code=start
class Solution {
 public:
  bool circularArrayLoop(vector<int>& a) {
    int n = a.size();
    const int BASE = 2000;
    for (int i = 0; i < n; i++) a[i] %= n;
    for (int i = 0; i < n; i++) {
      if (a[i] >= BASE || !a[i]) continue;
      int p = i, mark = BASE + i;
      bool sign = a[p] > 0;
      do {
        int ne = (p + a[p] + n) % n;
        a[p] = mark;
        p = ne;
      } while (a[p] && a[p] < BASE && sign == a[p] > 0);
      if (a[p] == mark) return true;
    }

    return false;
  }
};
// @lc code=end
