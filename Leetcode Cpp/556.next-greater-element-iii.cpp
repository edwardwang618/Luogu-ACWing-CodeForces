/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
class Solution {
 public:
 using ll = long long;
  int nextGreaterElement(int n) {
    string s = to_string(n);
    int i = s.size();
    while (i && s[i] <= s[i - 1]) i--;
    if (!i) return -1;
    int l = i, r = s.size() - 1;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (s[mid] > s[i - 1]) l = mid;
      else r = mid - 1;
    }
    swap(s[i - 1], s[l]);
    reverse(s.begin() + i, s.end());
    ll res = stol(s);
    if (res > INT_MAX) return -1;
    return (int) res;
  }
};
// @lc code=end
