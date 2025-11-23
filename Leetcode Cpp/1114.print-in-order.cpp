/*
 * @lc app=leetcode id=1114 lang=cpp
 *
 * [1114] Print in Order
 */

// @lc code=start
class Foo {
  //  public:
  // int cnt;
  // mutex mu;
  // condition_variable cv1, cv2;
  // Foo() { cnt = 0; }

  // void first(function<void()> printFirst) {
  //   {
  //     unique_lock<mutex> ul(mu);
  //     // printFirst() outputs "first". Do not change or remove this line.
  //     printFirst();
  //     cnt++;
  //   }
  //   cv1.notify_all();
  // }

  // void second(function<void()> printSecond) {
  //   {
  //     unique_lock<mutex> ul(mu);
  //     cv1.wait(ul, [this] { return cnt == 1; });
  //     ul.unlock();
  //     // printSecond() outputs "second". Do not change or remove this line.
  //     printSecond();
  //     cnt++;
  //   }
  //   cv2.notify_all();
  // }

  // void third(function<void()> printThird) {
  //   unique_lock<mutex> ul(mu);
  //   cv2.wait(ul, [this] { return cnt == 2; });
  //   // printThird() outputs "third". Do not change or remove this line.
  //   printThird();
  // }
 public:
  promise<void> p1, p2;
  Foo() {}
  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    p1.set_value();
  }

  void second(function<void()> printSecond) {
    p1.get_future().wait();
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    p2.set_value();
  }

  void third(function<void()> printThird) {
    p2.get_future().wait();
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
  }
};
// @lc code=end
