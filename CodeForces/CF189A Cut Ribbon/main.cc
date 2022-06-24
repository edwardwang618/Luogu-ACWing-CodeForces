#include <iostream>
#include <cstring>
using namespace std;

const int N = 4010;
int n, a[4];
int f[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 3; i++) scanf("%d", &a[i]);

  memset(f, -1, sizeof f);
  f[0] = 0;
  for (int i = 1; i <= 3; i++)
    for (int j = a[i]; j <= n; j++)
      if (~f[j - a[i]])
        f[j] = max(f[j], f[j - a[i]] + 1);

  printf("%d\n", f[n]);
}