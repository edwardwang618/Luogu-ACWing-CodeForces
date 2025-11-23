/*
 * @lc app=leetcode id=2069 lang=cpp
 *
 * [2069] Walking Robot Simulation II
 */

// @lc code=start
class Robot {
 public:
  int X, Y, dir;
  string direction[4] = {"East", "North", "West", "South"};
  int x, y;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  bool moved = false;

  Robot(int width, int height) {
    X = width;
    Y = height;
    x = y = dir = 0;
  }

  void step(int num) {
    moved = true;
    num %= (X - 1 + Y - 1) * 2;
    while (num) {
      int nx = x + dx[dir] * num, ny = y + dy[dir] * num;
      if (nx < 0 || nx >= X || ny < 0 || ny >= Y) {
        dir = (dir + 1) % 4;
        if (nx < 0) num -= x, x = 0;
        else if (nx >= X) num -= X - 1 - x, x = X - 1;
        else if (ny < 0) num -= y, y = 0;
        else num -= Y - 1 - y, y = Y - 1;
      } else {
        x = nx, y = ny;
        return;
      }
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() {
    if (moved && !x && !y) return direction[3];
    return direction[dir];
  }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// @lc code=end
