/*
 * @lc app=leetcode id=484 lang=cpp
 *
 * [484] Find Permutation
 */

// @lc code=start
class Solution {
public:
  vector<int> findPermutation(string &s) {
    int n = s.size();
    vector<int> res(n + 1);
    iota(res.begin(), res.end(), 1);

    for (int i = 0; i < n; i++)
      if (s[i] == 'D') {
        int j = i;
        while (j < n && s[j] == 'D') j++;
        reverse(res.begin() + i, res.begin() + j + 1);
        i = j;
      }
    return res;
  }
};
// @lc code=end
