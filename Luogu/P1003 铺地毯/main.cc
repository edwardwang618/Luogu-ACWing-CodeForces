#include <iostream>
using namespace std;

const int N = 1e4 + 10;
int n;
int x1[N], y1[N], x2[N], y2[N];
int x, y;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
    x2[i] += x1[i], y2[i] += y1[i];
  }

  scanf("%d%d", &x, &y);
  bool flag = false;
  for (int i = n; i; i--)
    if (x1[i] <= x && x <= x2[i] && y1[i] <= y && y <= y2[i]) {
      printf("%d\n", i);
      flag = true;
      break;
    }

  if (!flag) puts("-1");
}