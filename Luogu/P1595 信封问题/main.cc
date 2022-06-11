#include <iostream>
using namespace std;
const int N = 30;
int n;
long f[N];

int main() {
  scanf("%d", &n);
  f[1] = 0, f[2] = 1;
  for (int i = 3; i <= n; i++)
    f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
  printf("%ld\n", f[n]);
}