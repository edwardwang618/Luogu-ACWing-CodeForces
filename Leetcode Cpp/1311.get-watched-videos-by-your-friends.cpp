/*
 * @lc app=leetcode id=1311 lang=cpp
 *
 * [1311] Get Watched Videos by Your Friends
 */

// @lc code=start
class Solution {
 public:
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                        vector<vector<int>>& friends, int id,
                                        int k) {
    int n = friends.size();
    queue<int> q;
    int dist[n];
    memset(dist, -1, sizeof dist);
    dist[id] = 0;
    q.push(id);
    while (q.size()) {
      int t = q.front();
      q.pop();
      for (int x : friends[t]) {
        if (dist[x] == -1) {
          dist[x] = dist[t] + 1;
          q.push(x);
        }
      }
    }

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
      if (dist[i] == k)
        for (auto& s : watchedVideos[i]) mp[s]++;

    pair<int, string> items[mp.size()];
    n = 0;
    for (auto& [k, v] : mp) items[n++] = {v, k};
    sort(items, items + n);
    vector<string> res;
    for (auto& p : items) res.push_back(p.second);
    return res;
  }
};
// @lc code=end
