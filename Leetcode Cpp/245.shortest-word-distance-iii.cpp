/*
 * @lc app=leetcode id=245 lang=cpp
 *
 * [245] Shortest Word Distance III
 */

// @lc code=start
class Solution {
 public:
  int shortestWordDistance(vector<string>& v, string s1, string s2) {
    int res = v.size();
    if (s1 == s2) {
      int last = -1;
      for (int k = 0; k < v.size(); k++)
        if (v[k] == s1) {
          if (~last) res = min(res, k - last);
          last = k;
        }
    } else {
      for (int k = 0, i = -1, j = -1; k < v.size(); k++) {
        if (v[k] == s1) i = k;
        if (v[k] == s2) j = k;
        if (~i && ~j) res = min(res, abs(i - j));
      }
    }

    return res;
  }
};
// @lc code=end
