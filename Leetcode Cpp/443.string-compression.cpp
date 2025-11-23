/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
 public:
  int compress(vector<char>& v) {
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
      int j = i;
      while (j < v.size() && v[i] == v[j]) j++;
      int cnt = j - i;
      v[res++] = v[i];
      if (cnt > 1) {
        auto s = to_string(cnt);
        for (char ch : s) v[res++] = ch;
      }

      i = j - 1;
    }

    return res;
  }
};
// @lc code=end
