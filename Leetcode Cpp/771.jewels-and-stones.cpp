/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
class Solution {
public:
  int numJewelsInStones(string &jewels, string &stones) {
    unordered_set<char> st(jewels.begin(), jewels.end());
    int res = 0;
    for (char ch : stones) res += st.count(ch);
    return res;
  }
};
// @lc code=end
