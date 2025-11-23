/*
 * @lc app=leetcode id=1195 lang=cpp
 *
 * [1195] Fizz Buzz Multithreaded
 */

// @lc code=start
class FizzBuzz {
 private:
  int n;
  int cnt;
  mutex mu;
  condition_variable cv;

 public:
  FizzBuzz(int n) {
    this->n = n;
    cnt = 1;
  }

  void run(const function<bool()>& check, const function<void(int)>& print) {
    while (cnt <= n) {
      unique_lock<mutex> ul(mu);
      cv.wait(ul, check);
      if (cnt > n) break;
      print(cnt++);
      cv.notify_all();
    }
  }

  // printFizz() outputs "fizz".
  void fizz(function<void()> printFizz) {
    run([this] { return (cnt % 3 == 0 && cnt % 5) || cnt > n; },
        [&](int x) { printFizz(); });
  }

  // printBuzz() outputs "buzz".
  void buzz(function<void()> printBuzz) {
    run([this] { return (cnt % 3 && cnt % 5 == 0) || cnt > n; },
        [&](int x) { printBuzz(); });
  }

  // printFizzBuzz() outputs "fizzbuzz".
  void fizzbuzz(function<void()> printFizzBuzz) {
    run([this] { return cnt % 15 == 0 || cnt > n; },
        [&](int x) { printFizzBuzz(); });
  }

  // printNumber(x) outputs "x", where x is an integer.
  void number(function<void(int)> printNumber) {
    run([this] { return (cnt % 3 && cnt % 5) || cnt > n; },
        [&](int x) { printNumber(x); });
  }
};
// @lc code=end
