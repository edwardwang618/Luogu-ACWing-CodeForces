/*
 * @lc app=leetcode id=157 lang=cpp
 *
 * [157] Read N Characters Given Read4
 */

// @lc code=start
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    int res = 0;
    char buf4[4];
    while (res < n) {
      int x = read4(buf4);
      for (int i = 0; i < x; i++) {
        buf[res++] = buf4[i];
        if (res == n) return res;
      }
      if (x < 4) break;
    }

    return res;
  }
};
// @lc code=end
