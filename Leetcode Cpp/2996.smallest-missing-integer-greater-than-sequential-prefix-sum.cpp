/*
 * @lc app=leetcode id=2996 lang=cpp
 *
 * [2996] Smallest Missing Integer Greater Than Sequential Prefix Sum
 */

// @lc code=start
class Solution {
 public:
  int missingInteger(vector<int>& a) {
    unordered_set<int> st;
    for (int x : a) st.insert(x);
    int sum = a[0];
    for (int i = 0; i + 1 < a.size(); i++)
      if (a[i + 1] == a[i] + 1)
        sum += a[i + 1];
      else
        break;
    while (st.count(sum)) sum++;
    return sum;
  }
};
// @lc code=end
