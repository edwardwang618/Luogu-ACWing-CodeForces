#include <iostream>
using namespace std;

void exgcd(int a, int b, int& x, int& y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }

  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, x, y;
    cin >> a >> b;
    exgcd(a, b, x, y);

    printf("%d %d\n", x, y);
  }
}