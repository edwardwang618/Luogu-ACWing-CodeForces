/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
 public:
  vector<int> majorityElement(vector<int>& a) {
    int cnt1 = 0, cnt2 = 0, *p = nullptr, *q = nullptr;
    int x1, x2;
    for (int x : a) {
      if (p && *p == x) cnt1++;
      else if (q && *q == x) cnt2++;
      else if (!cnt1) {
        delete p;
        p = new int(x), cnt1++;
      } else if (!cnt2) {
        delete q;
        q = new int(x), cnt2++;
      } else cnt1--, cnt2--;
    }

    cnt1 = cnt2 = 0;
    for (int x : a)
      if (x == *p) cnt1++;
      else if (x == *q) cnt2++;

    vector<int> res;
    if (cnt1 > a.size() / 3) res.push_back(*p);
    if (cnt2 > a.size() / 3) res.push_back(*q);
    return res;
  }
};
// @lc code=end
