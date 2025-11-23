/*
 * @lc app=leetcode id=244 lang=cpp
 *
 * [244] Shortest Word Distance II
 */

// @lc code=start
class WordDistance {
 public:
  unordered_map<string, vector<int>> mp;
  int n;
  WordDistance(vector<string>& v) {
    n = v.size();
    for (int i = 0; i < n; i++) mp[v[i]].push_back(i);
  }

  int shortest(string word1, string word2) {
    auto &v1 = mp[word1], &v2 = mp[word2];
    int res = n;
    for (int i = 0, j = 0; i < v1.size() && j < v2.size();) {
      res = min(res, abs(v1[i] - v2[j]));
      if (v1[i] < v2[j]) i++;
      else j++;
    }

    return res;
  }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
// @lc code=end
