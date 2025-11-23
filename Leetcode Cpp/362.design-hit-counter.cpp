/*
 * @lc app=leetcode id=362 lang=cpp
 *
 * [362] Design Hit Counter
 */

// @lc code=start
class HitCounter {
 public:
  queue<int> q;
  HitCounter() {}

  void hit(int timestamp) { q.push(timestamp); }

  int getHits(int timestamp) {
    while (q.size() && q.front() <= timestamp - 300) q.pop();
    return q.size();
  }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
// @lc code=end
