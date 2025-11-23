/*
 * @lc app=leetcode id=1226 lang=cpp
 *
 * [1226] The Dining Philosophers
 */

// @lc code=start
class DiningPhilosophers {
 public:
  mutex lock[5];
  condition_variable cv;
  bool eating[5];
  DiningPhilosophers() { memset(eating, 0, sizeof eating); }

  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    int lf = (philosopher + 4) % 5, rf = (philosopher + 1) % 5;
    unique_lock<mutex> lk(lock[philosopher]);
    cv.wait(lk, [&] { return !eating[lf] && !eating[rf]; });
    eating[philosopher] = true;
    lock[rf].lock();
    lock[lf].lock();
    pickLeftFork();
    pickRightFork();
    eat();
    putRightFork();
    putLeftFork();
    lock[lf].unlock();
    lock[rf].unlock();
    eating[philosopher] = false;
    cv.notify_all();
  }
};
// @lc code=end
