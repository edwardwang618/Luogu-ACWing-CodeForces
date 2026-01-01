/*
 * @lc app=leetcode id=1115 lang=cpp
 *
 * [1115] Print FooBar Alternately
 */

// @lc code=start
class FooBar {
 private:
  int n;
  bool run_foo;
  mutex mu;
  condition_variable cv;

 public:
  FooBar(int n) {
    this->n = n;
    run_foo = true;
  }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> ul(mu);
      cv.wait(ul, [this] { return run_foo; });
      // printFoo() outputs "foo". Do not change or remove this line.
      printFoo();
      run_foo = false;
      cv.notify_all();
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      unique_lock<mutex> ul(mu);
      cv.wait(ul, [this] { return !run_foo; });
      // printBar() outputs "bar". Do not change or remove this line.
      printBar();
      run_foo = true;
      cv.notify_all();
    }
  }
};
// @lc code=end
