#include <iostream>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b, a || b) {
    int res = 0, t = 0;
    while (a || b) {
      t += a % 10 + b % 10;
      t /= 10;
      res += t;
      a /= 10;
      b /= 10;
    }
    if (!res)
      puts("No carry operation.");
    else if (res == 1)
      puts("1 carry operation.");
    else
      printf("%d carry operations.\n", res);
  }
}