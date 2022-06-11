#include <iostream>
#include <algorithm>
#include <limits.h>
#define first x
#define second y
using namespace std;
using PII = pair<int, int>;

const int N = 2e5 + 10;
int n;
PII a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].x);
    a[i].y = i;
  }

  sort(a, a + n);
  int res = 1, last = INT_MAX, dir = -1;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && a[j].x == a[i].x) j++;
    int minp = a[i].y, maxp = a[j - 1].y;
    if (dir == -1) {
      if (last > maxp) last = minp;
      else dir = 1, last = maxp;
    } else {
      if (last < minp) last = maxp;
      else {
        res++;
        dir = -1;
        last = minp;
      }
    }

    i = j;
  }

  printf("%d\n", res);
}