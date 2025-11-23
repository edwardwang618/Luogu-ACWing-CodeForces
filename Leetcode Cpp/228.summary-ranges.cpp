/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

// @lc code=start
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& a) {
    vector<string> res;
    for (int i = 0; i < a.size(); i++) {
      int j = i;
      while (j + 1 < a.size() && a[j] + 1 == a[j + 1]) j++;
      if (j != i)
        res.push_back(to_string(a[i]) + "->" + to_string(a[j]));
      else
        res.push_back(to_string(a[i]));
      i = j;
    }
    return res;
  }
};
// @lc code=end
