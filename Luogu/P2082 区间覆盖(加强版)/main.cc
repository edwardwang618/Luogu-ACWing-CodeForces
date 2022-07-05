#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
using PLL = pair<long, long>;

const int N = 1e5 + 10;
int n;
PLL a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) 
    scanf("%ld%ld", &a[i].x, &a[i].y);
  sort(a, a + n);

  long res = 0, r = -1e19;
  for (int i = 0; i < n; i++)
    if (r <= a[i].y) {
      res += a[i].y - max(r, a[i].x) + 1;
      r = a[i].y + 1;
    }
  printf("%ld\n", res);
}