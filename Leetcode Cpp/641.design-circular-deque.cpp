/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque {
public:
  int *buf;
  int head, tail;
  int sz, cap;

  MyCircularDeque(int k) : head(0), tail(0), sz(0), cap(k) { buf = new int[k]; }
  ~MyCircularDeque() { delete[] buf; }

  bool insertFront(int x) {
    if (isFull())
      return false;
    head = (head - 1 + cap) % cap;
    buf[head] = x;
    sz++;
    return true;
  }

  bool insertLast(int x) {
    if (isFull())
      return false;
    buf[tail] = x;
    tail = (tail + 1) % cap;
    sz++;
    return true;
  }

  bool deleteFront() {
    if (isEmpty())
      return false;
    head = (head + 1) % cap;
    sz--;
    return true;
  }

  bool deleteLast() {
    if (isEmpty())
      return false;
    tail = (tail - 1 + cap) % cap;
    sz--;
    return true;
  }

  int getFront() {
    if (isEmpty())
      return -1;
    return buf[head];
  }

  int getRear() {
    if (isEmpty())
      return -1;
    return buf[(tail - 1 + cap) % cap];
  }

  bool isEmpty() { return !sz; }

  bool isFull() { return sz == cap; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
