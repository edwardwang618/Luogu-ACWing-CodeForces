/*
 * @lc app=leetcode id=1348 lang=cpp
 *
 * [1348] Tweet Counts Per Frequency
 */

// @lc code=start
class TweetCounts {
  unordered_map<string, multiset<int>> mp;

public:
  TweetCounts() {}

  void recordTweet(const string &tweet, int time) { mp[tweet].insert(time); }

  vector<int> getTweetCountsPerFrequency(const string &freq,
                                         const string &tweet, int startT,
                                         int endT) {
    int delta = freq == "minute" ? 60 : freq == "hour" ? 3600 : 86400;
    auto &ts = mp[tweet];
    vector<int> res((endT - startT) / delta + 1);
    for (auto it = ts.lower_bound(startT); it != ts.end() && *it <= endT; ++it)
      res[(*it - startT) / delta]++;
    return res;
  }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 =
 * obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
// @lc code=end
