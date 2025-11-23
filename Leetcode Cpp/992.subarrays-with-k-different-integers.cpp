/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 */

// @lc code=start
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& a, int k) {
    int res = 0;
    unordered_map<int, int> mp1, mp2;
    for (int i = 0, j1 = 0, j2 = 0, cnt1 = 0, cnt2 = 0; i < a.size(); i++) {
      if (!mp1[a[i]]) cnt1++;
      mp1[a[i]]++;
      if (!mp2[a[i]]) cnt2++;
      mp2[a[i]]++;
      while (cnt1 > k) if (!--mp1[a[j1++]]) cnt1--;
      while (cnt2 > k - 1) if (!--mp2[a[j2++]]) cnt2--;
      res += j2 - j1;
    }

    return res;
  }
};
// @lc code=end
