#include <iostream>
using namespace std;

long a, b, m;

long fast_pow() {
  long res = 1;
  while (b) {
    if (b & 1) res = res * a % m;
    b >>= 1L;
    a = a * a % m;
  }
  return res;
}

int main() {
  scanf("%ld%ld", &a, &m);
  long phi = m, tmp = m;
  for (int i = 2; i <= tmp / i; i++) {
    if (tmp % i == 0) {
      phi = phi / i * (i - 1);
      while (tmp % i == 0) tmp /= i;
    }
  }

  if (tmp > 1) phi = phi / tmp * (tmp - 1);

  char ch;
  bool flag = false;
  while (!isdigit(ch = getchar()));
  for (; isdigit(ch); ch = getchar()) {
    b = b * 10 + ch - '0';
    if (b >= phi) {
      flag = true;
      b %= phi;
    }
  }
  if (flag) b += phi;
  printf("%ld\n", fast_pow());
}