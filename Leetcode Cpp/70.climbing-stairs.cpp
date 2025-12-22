/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
// class Solution {
//  public:
//   int climbStairs(int n) {
//     if (n <= 1) return 1;
//     int n0 = 1, n1 = 1;
//     for (int i = 1; i < n; i++) {
//       n1 = n0 + n1;
//       n0 = n1 - n0;
//     }
//     return n1;
//   }
// };

class Solution {
public:
  using ll = long long;
  struct Mat {
    ll a00, a01, a10, a11;
  };

  static Mat mul(Mat &x, Mat &y) {
    return {x.a00 * y.a00 + x.a01 * y.a10, x.a00 * y.a01 + x.a01 * y.a11,
            x.a10 * y.a00 + x.a11 * y.a10, x.a10 * y.a01 + x.a11 * y.a11};
  }

  static const Mat I() {
    static const Mat I = {1, 0, 0, 1};
    return I;
  }

  static Mat mpow(Mat base, int k) {
    Mat res{I()};
    while (k) {
      if (k & 1)
        res = mul(res, base);
      base = mul(base, base);
      k >>= 1;
    }
    return res;
  }

  int climbStairs(int n) { return (int)mpow({1, 1, 1, 0}, n).a00; }
};

// @lc code=end
