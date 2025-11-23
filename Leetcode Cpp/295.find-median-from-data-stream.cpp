/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
 public:
  priority_queue<int> max_heap;
  priority_queue<int, vector<int>, greater<>> min_heap;
  MedianFinder() {}

  void addNum(int x) {
    if (min_heap.size() && x > min_heap.top())
      min_heap.push(x);
    else
      max_heap.push(x);
    adjust();
  }

  void adjust() {
    if (max_heap.size() > min_heap.size() + 1) {
      min_heap.push(max_heap.top());
      max_heap.pop();
    } else if (max_heap.size() < min_heap.size()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  double findMedian() {
    if (max_heap.size() == min_heap.size())
      return ((double)max_heap.top() + min_heap.top()) / 2;
    return max_heap.top();
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
