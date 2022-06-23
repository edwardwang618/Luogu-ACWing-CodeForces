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
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= 3; j++)
      if (i >= a[j] && ~f[i - a[j]])
        f[i] = max(f[i], f[i - a[j]] + 1);
  
  printf("%d\n", f[n]);
}