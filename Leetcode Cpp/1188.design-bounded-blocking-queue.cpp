/*
 * @lc app=leetcode id=1188 lang=cpp
 *
 * [1188] Design Bounded Blocking Queue
 */

// @lc code=start
class BoundedBlockingQueue {
private:
  mutex mu;
  condition_variable cv_full, cv_empty;
  queue<int> q;
  int capacity;

public:
  BoundedBlockingQueue(int capacity) { this->capacity = capacity; }

  void enqueue(int element) {
    {
      unique_lock<mutex> lk(mu);
      cv_full.wait(lk, [this] { return q.size() < capacity; });
      q.push(element);
    }
    cv_empty.notify_one();
  }

  int dequeue() {
    {
      unique_lock<mutex> lk(mu);
      cv_empty.wait(lk, [this] { return q.size() > 0; });
      int x = q.front();
      q.pop();
    }
    cv_full.notify_one();
    return x;
  }

  int size() {
    lock_guard<mutex> lk(mu);
    return q.size();
  }
};
// @lc code=end
