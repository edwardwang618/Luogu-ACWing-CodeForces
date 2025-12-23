/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
  int longestConsecutive(vector<int> &a) {
    unordered_set<int> st(a.begin(), a.end());
    int res = 0;
    while (st.size()) {
      int x = *st.begin(), y = x + 1, len = 0;
      unordered_set<int>::iterator it;
      while (it = st.find(x), it != st.end()) {
        st.erase(it);
        x--;
        len++;
      }
      while (it = st.find(y), it != st.end()) {
        st.erase(it);
        y++;
        len++;
      }
      res = max(res, len);
    }
    return res;
  }
};
// @lc code=end
