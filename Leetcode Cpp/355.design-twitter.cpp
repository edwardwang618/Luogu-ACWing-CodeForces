/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter {
public:
  int timestamp = 0;
  using PII = pair<int, int>;
  unordered_map<int, vector<PII>> tweets;
  unordered_map<int, unordered_set<int>> following;
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_back(timestamp++, tweetId);
  }

  struct Node {
    int idx, timestamp;
    vector<PII> *tv;
    bool operator<(const Node &other) const {
      return timestamp < other.timestamp;
    }
  };

  vector<int> getNewsFeed(int userId) {
    priority_queue<Node> heap;
    {
      auto &v = tweets[userId];
      if (v.size())
        heap.push(Node{(int)v.size() - 1, v.back().first, &v});
    }
    {
      auto &following_list = following[userId];
      for (int followee : following_list) {
        auto &v = tweets[followee];
        if (v.size())
          heap.push(Node{(int)v.size() - 1, v.back().first, &v});
      }
    }
    vector<int> res;
    res.reserve(10);
    while (heap.size()) {
      auto cur = heap.top();
      heap.pop();
      res.push_back((*cur.tv)[cur.idx].second);
      if (res.size() == 10)
        break;
      if (cur.idx) {
        int nidx = cur.idx - 1;
        heap.push(Node{nidx, (*cur.tv)[nidx].first, cur.tv});
      }
    }
    return res;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    following[followerId].erase(followeeId);
  }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
