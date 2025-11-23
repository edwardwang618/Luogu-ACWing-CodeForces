/*
 * @lc app=leetcode id=1116 lang=cpp
 *
 * [1116] Print Zero Even Odd
 */

// @lc code=start
class ZeroEvenOdd {
 private:
  int n;
  int turn, cnt;
  mutex mu;
  condition_variable cv;

 public:
  ZeroEvenOdd(int n) {
    this->n = n;
    turn = 0;
    cnt = 1;
  }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    while (cnt <= n) {
      unique_lock<mutex> ul(mu);
      cv.wait(ul, [this] { return turn == 0 || cnt > n; });
      if (cnt > n) break;
      printNumber(0);
      turn = cnt % 2 == 0 ? 2 : 1;
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    while (cnt <= n) {
      unique_lock<mutex> ul(mu);
      cv.wait(ul, [this] { return turn == 2 || cnt > n; });
      if (cnt > n) break;
      printNumber(cnt++);
      turn = 0;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    while (cnt <= n) {
      unique_lock<mutex> ul(mu);
      cv.wait(ul, [this] { return turn == 1 || cnt > n; });
      if (cnt > n) break;
      printNumber(cnt++);
      turn = 0;
      cv.notify_all();
    }
  }
};
// @lc code=end
