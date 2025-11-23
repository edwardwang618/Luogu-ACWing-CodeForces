/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    static vector<string> ss{"abc", "def",  "ghi", "jkl",
                             "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    if (digits.empty()) return res;
    string s;
    dfs(0, s, digits, res, ss);
    return res;
  }

  void dfs(int u, string& s, string& ds, vector<string>& res,
           vector<string>& ss) {
    if (u == ds.size()) {
      res.push_back(s);
      return;
    }

    for (char ch : ss[ds[u] - '2']) {
      s += ch;
      dfs(u + 1, s, ds, res, ss);
      s.pop_back();
    }
  }
};
// @lc code=end
