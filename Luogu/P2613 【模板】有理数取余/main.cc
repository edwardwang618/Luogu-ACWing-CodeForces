#include <iostream>

using namespace std;

const int P = 19260817;
int a, b;

void fast_read(int &x) {
  char ch;
  while (!isdigit(ch = getchar()));
  for (; isdigit(ch); ch = getchar()) {
    x = x * 10 + ch - '0';
    x %= P;
  }
}

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }

  int d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  fast_read(a);
  fast_read(b);
  int x, y;
  int d = exgcd(b, P, x, y);
  if (a % d) puts("Angry!");
  else printf("%ld\n", ((long) x * a / d % P + P) % P);
}