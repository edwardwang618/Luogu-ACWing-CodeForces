/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
public:
  int *buf;
  int cap;
  int head, tail;

  MyCircularQueue(int k) : buf(new int[k + 1]), cap(k + 1), head(0), tail(0) {}
  ~MyCircularQueue() { delete[] buf; }

  bool enQueue(int x) {
    if (isFull())
      return false;
    buf[tail] = x;
    tail = (tail + 1) % cap;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    head = (head + 1) % cap;
    return true;
  }

  int Front() { return isEmpty() ? -1 : buf[head]; }

  int Rear() { return isEmpty() ? -1 : buf[(tail - 1 + cap) % cap]; }

  bool isEmpty() { return head == tail; }

  bool isFull() { return (tail + 1) % cap == head; }
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
