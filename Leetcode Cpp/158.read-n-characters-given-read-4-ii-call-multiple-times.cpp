/*
 * @lc app=leetcode id=158 lang=cpp
 *
 * [158] Read N Characters Given read4 II - Call Multiple Times
 */

// @lc code=start
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  char buf4[4];
  int head, tail;

  Solution() { head = tail = 0; }

  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    int res = 0;
    while (res < n) {
      if (head == tail) {
        head = 0;
        tail = read4(buf4);
      }
      if (!tail) break;
      while (res < n && head < tail) buf[res++] = buf4[head++];
    }

    return res;
  }
};
// @lc code=end
