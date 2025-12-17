/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
public:
  int *buf;
  int head, tail;
  int sz, cap;

  MyCircularQueue(int k) : head(0), tail(0), cap(k), sz(0) { buf = new int[k]; }
  ~MyCircularQueue() { delete[] buf; }

  bool enQueue(int x) {
    if (isFull())
      return false;
    buf[tail] = x;
    tail = (tail + 1) % cap;
    sz++;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    head = (head + 1) % cap;
    sz--;
    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;
    return buf[head];
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return buf[(tail + cap - 1) % cap];
  }

  bool isEmpty() { return !sz; }

  bool isFull() { return sz == cap; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end
