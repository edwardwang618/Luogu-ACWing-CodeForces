#include <iostream>
using namespace std;

int T, M, H;

int main() {
  scanf("%d", &T);
  auto f = [](int a, int b, int p) {
    int res = 1 % p;
    a %= p;
    while (b) {
      if (b & 1) res = res * a % p;
      a = a * a % p;
      b >>= 1;
    }
    return res;
  }; 
  while (T--) {
    scanf("%d%d", &M, &H);
    int res = 0;
    for (int i = 1; i <= H; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      res = (res + f(a, b, M)) % M;
    }
    printf("%d\n", res);
  }
}