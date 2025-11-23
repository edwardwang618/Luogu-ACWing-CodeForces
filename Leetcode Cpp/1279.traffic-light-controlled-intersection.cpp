/*
 * @lc app=leetcode id=1279 lang=cpp
 *
 * [1279] Traffic Light Controlled Intersection
 */

// @lc code=start
class TrafficLight {
 private:
  mutex mu;
  condition_variable cv;
  int green;
  bool has_car[2];

 public:
  TrafficLight() : green(0) { has_car[0] = has_car[1] = false; }

  void carArrived(int carId,      // ID of the car
                  int roadId,     // ID of the road the car travels on. Can be 1
                                  // (road A) or 2 (road B)
                  int direction,  // Direction of the car
                  function<void()> turnGreen,  // Use turnGreen() to turn light
                                               // to green on current road
                  function<void()> crossCar  // Use crossCar() to make car cross
                                             // the intersection
  ) {
    roadId--;
    unique_lock<mutex> lk(mu);
    has_car[roadId] = true;
    cv.wait(lk, [&] { return green == roadId || !has_car[roadId ^ 1]; });
    if (green != roadId) turnGreen();
    green = roadId;
    crossCar();
    has_car[roadId] = false;
    cv.notify_all();
  }
};
// @lc code=end
