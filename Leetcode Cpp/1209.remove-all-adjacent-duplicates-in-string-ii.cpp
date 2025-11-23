/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
 public:
#define x first
#define y second
  string removeDuplicates(string s, int k) {
    vector<pair<char, int>> stk;
    for (int i = 0; i < s.size(); i++) {
      int j = i;
      while (j < s.size() && s[i] == s[j]) j++;
      if (stk.empty() || stk.back().x != s[i])
        stk.push_back({s[i], (j - i) % k});
      else
        stk.back().y = (stk.back().y + j - i) % k;
      if (!stk.back().y) stk.pop_back();
      i = j - 1;
    }

    string res;
    for (auto &p : stk) res.insert(res.end(), p.y, p.x);

    return res;
  }
};
// @lc code=end
