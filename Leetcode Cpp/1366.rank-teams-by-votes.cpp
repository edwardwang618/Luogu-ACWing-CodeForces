/*
 * @lc app=leetcode id=1366 lang=cpp
 *
 * [1366] Rank Teams by Votes
 */

// @lc code=start
class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    unordered_map<char, vector<int>> mp;
    int n = votes[0].size();
    for (auto& vote : votes)
      for (int i = 0; i < n; i++) {
        if (!mp.count(vote[i])) mp[vote[i]] = vector<int>(n, 0);
        mp[vote[i]][i]++;
      }

    string res = votes[0];
    sort(res.begin(), res.end(), [&](char a, char b) {
      auto &av = mp[a], &bv = mp[b];
      for (int i = 0; i < n; i++)
        if (av[i] != bv[i]) return av[i] > bv[i];
      return a < b;
    });

    return res;
  }
};
// @lc code=end
