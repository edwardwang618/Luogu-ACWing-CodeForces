#include <iostream>
using namespace std;

const int N = 1e5 + 10, P = 5000011;
int n, k;
int f[N];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0, s = 0; i <= n; i++) {
    if (i < k + 1) f[i] = 1;
    else {
      s = (s + f[i - k - 1]) % P;
      f[i] = s;
    }
  }

  int res = 0;
  for (int i = 0; i <= n; i++) res = (res + f[i]) % P;
  printf("%d\n", res);
}