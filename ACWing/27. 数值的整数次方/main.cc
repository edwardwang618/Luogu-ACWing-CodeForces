class Solution {
public:
  double Power(double base, int exponent) {
    long k = exponent;
    if (k < 0) base = 1.0 / base, k *= -1;
    double res = 1.0;
    while (k) {
      if (k & 1) res *= base;
      base *= base;
      k >>= 1;
    }

    return res;
  }
};