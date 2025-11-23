/*
 * @lc app=leetcode id=721 lang=cpp
 *
 * [721] Accounts Merge
 */

// @lc code=start
class Solution {
 public:
  vector<int> p;
  int idx;
  unordered_map<string, int> email_to_int;
  unordered_map<int, string> int_to_email;
  unordered_map<int, string> name_mp;
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  void merge(string& x, string& y) {
    if (!email_to_int.count(x)) {
      email_to_int[x] = idx;
      int_to_email[idx++] = x;
    }
    if (!email_to_int.count(y)) {
      email_to_int[y] = idx;
      int_to_email[idx++] = y;
    }
    int px = find(email_to_int[x]), py = find(email_to_int[y]);
    p[px] = py;
  }
  vector<vector<string>> accountsMerge(vector<vector<string>>& as) {
    int cnt = 0;
    for (auto& v : as) cnt += v.size() - 1;
    p.resize(cnt);
    for (int i = 0; i < p.size(); i++) p[i] = i;
    for (auto& acct : as) {
      auto name = acct[0];
      string a1 = acct[1];
      if (acct.size() == 2) merge(a1, a1);
      for (int i = 2; i < acct.size(); i++) merge(acct[i], a1);
      name_mp[find(email_to_int[a1])] = name;
    }

    unordered_map<int, set<string>> group_mp;
    for (auto& acct : as) {
      string a1 = acct[1];
      int pp = find(email_to_int[a1]);
      for (int i = 1; i < acct.size(); i++) group_mp[pp].insert(acct[i]);
    }
    vector<vector<string>> res;
    for (auto& [k, v] : group_mp) {
      vector<string> vv;
      string name = name_mp[k];
      vv.push_back(name);
      vv.insert(vv.end(), v.begin(), v.end());
      res.push_back(vv);
    }
    return res;
  }
};
// @lc code=end
