/*
 * @lc app=leetcode id=346 lang=cpp
 *
 * [346] Moving Average from Data Stream
 */

// @lc code=start
class MovingAverage {
 public:
  double sum;
  int capacity;
  queue<double> q;

  MovingAverage(int size) {
    capacity = size;
    sum = 0.0;
  }

  double next(int val) {
    sum += val;
    q.push(val);
    if (q.size() > capacity) {
      sum -= q.front(); q.pop();
    }
    return sum / q.size();
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end
