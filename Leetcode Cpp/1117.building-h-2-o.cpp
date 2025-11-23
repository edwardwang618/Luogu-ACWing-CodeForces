/*
 * @lc app=leetcode id=1117 lang=cpp
 *
 * [1117] Building H2O
 */

// @lc code=start
class H2O {
 public:
  int hcnt;
  mutex mu;
  condition_variable cv;

  H2O() { hcnt = 0; }

  void hydrogen(function<void()> releaseHydrogen) {
    unique_lock<mutex> ul(mu);
    cv.wait(ul, [&] { return hcnt; });

    // releaseHydrogen() outputs "H". Do not change or remove this line.
    releaseHydrogen();
    hcnt--;
    cv.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {
    unique_lock<mutex> ul(mu);
    cv.wait(ul, [&] { return !hcnt; });

    // releaseOxygen() outputs "O". Do not change or remove this line.
    releaseOxygen();
    hcnt += 2;
    cv.notify_all();
  }
};
// @lc code=end
