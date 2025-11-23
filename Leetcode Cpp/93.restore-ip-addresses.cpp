/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string p;
    dfs(0, p, 0, s, res);
    return res;
  }

  void dfs(int u, string& p, int cut, string& s, vector<string>& res) {
    if (u == s.size()) {
      if (cut == 4) res.push_back(p.substr(0, p.size() - 1));
      return;
    }

    for (int i = u; i < s.size(); i++) {
      string cur = s.substr(u, i - u + 1);
      if ((cur[0] != '0' || cur == "0") && stoi(cur) <= 255 && cut < 4) {
        p += cur + ".";
        dfs(i + 1, p, cut + 1, s, res);
        p.erase(p.size() - cur.size() - 1);
      } else if (cur.size() > 3)
        break;
    }
  }
};
// @lc code=end
