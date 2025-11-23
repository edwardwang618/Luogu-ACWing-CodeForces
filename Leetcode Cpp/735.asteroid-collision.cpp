/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
 public:
  vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> stk;
    for (int asteroid : asteroids) {
      if (asteroid > 0)
        stk.push(asteroid);
      else {
        if (stk.empty() || stk.top() < 0) {
          stk.push(asteroid);
          continue;
        }

        bool exploded = false;
        while (!stk.empty() && stk.top() > 0) {
          if (stk.top() > -asteroid) {
            exploded = true;
            break;
          } else if (stk.top() == -asteroid) {
            exploded = true;
            stk.pop();
            break;
          } else if (stk.top() < -asteroid)
            stk.pop();
        }

        // 如果asteroid没炸，则入栈
        if (!exploded) stk.push(asteroid);
      }
    }

    vector<int> res(stk.size());
    for (int i = res.size() - 1; i >= 0; --i) {
      res[i] = stk.top();
      stk.pop();
    }

    return res;
  }
};
// @lc code=end
