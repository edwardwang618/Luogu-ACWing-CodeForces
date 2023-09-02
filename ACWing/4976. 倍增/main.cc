#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, x;

int get(int x) {
  while (x % 2 == 0) x /= 2;
  while (x % 3 == 0) x /= 3;
  return x;
}

int main() {
  scanf("%d", &n);
  bool flag = false;
  for (int i = 1; i <= n; i++) {
    int y;
    scanf("%d", &y);
    if (i == 1) x = get(y);
    else if (x != get(y)) {
      puts("No");
      flag = true;
      break;
    }
  }

  if (!flag) puts("Yes");
}