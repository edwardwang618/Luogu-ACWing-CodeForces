/*
 * @lc app=leetcode id=353 lang=cpp
 *
 * [353] Design Snake Game
 */

// @lc code=start
class SnakeGame {
#define x first
#define y second
  using PII = pair<int, int>;

 private:
  int m, n;
  int score, food_idx;
  vector<vector<int>> food;
  deque<PII> dq;
  struct phash {
    int operator()(const PII &p) const {
      return hash<int>()(p.x) ^ hash<int>()(p.y);
    }
  };
  unordered_set<PII, phash> st;

 public:
  SnakeGame(int width, int height, vector<vector<int>> &food)
      : n(width), m(height), score(0), food_idx(0), food(std::move(food)) {
    dq.emplace_back(0, 0);
    st.insert({0, 0});
  }

  int move(string dir) {
    char d = dir[0];
    int x = dq.front().x, y = dq.front().y;
    x += d == 'D' ? 1 : 0;
    x += d == 'U' ? -1 : 0;
    y += d == 'L' ? -1 : 0;
    y += d == 'R' ? 1 : 0;

    if (x < 0 || x >= m || y < 0 || y >= n) return -1;
    pair cur{x, y};
    if (food_idx < food.size())
      if (x == food[food_idx][0] && y == food[food_idx][1]) {
        score++;
        dq.emplace_front(x, y);
        st.insert({x, y});
        food_idx++;
        return score;
      }

    auto tail = dq.back();
    dq.pop_back();
    st.erase(tail);
    if (st.count(cur)) return -1;
    dq.emplace_front(x, y);
    st.insert({x, y});
    return score;
  }
};
/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
// @lc code=end
