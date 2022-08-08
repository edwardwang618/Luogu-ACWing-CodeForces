#include <iostream>
using namespace std;

long a, b;

long exgcd(long a, long b, long& x, long& y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }

  long d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  scanf("%ld%ld", &a, &b);
  long x, y;
  exgcd(a, b, x, y);
  x = (x % b + b) % b;
  printf("%ld\n", x);
}