#include <iostream>
using namespace std;

const int N = 3003;
int a[1005][N];

void init() {
  a[1][0] = a[1][1] = 1;
  for (int i = 2; i <= 1000; i++) {
    a[i][0] = 1;
    int t = 0, j;
    for (j = 1; j <= a[i - 1][0]; j++) {
      a[i][j] = a[i - 1][j] * i + t;
      t = a[i][j] / 10;
      a[i][j] %= 10;
    }

    while (t) {
      a[i][j] = t % 10;
      t /= 10;
      j++;
    }

    a[i][0] = j - 1;
  }
}

int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    int res = 0;
    for (int i = 1; i <= a[n][0]; i++)
      if (a[n][i] == k) res++;

    printf("%d\n", res);
  }
}