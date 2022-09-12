#include <iostream>
using namespace std;

int n, i, j, k;

bool work() {
  for (i = 0; 3 * i <= n; i++)
    for (j = 0; 3 * i + 5 * j <= n; j++) {
      k = n - 3 * i - 5 * j;
      if (k % 7 == 0) return true;
    }
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    if (!work()) puts("-1");
    else printf("%d %d %d\n", i, j, k / 7);
  }
}