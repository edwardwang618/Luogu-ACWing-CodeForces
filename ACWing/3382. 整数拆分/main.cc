#include <iostream>
using namespace std;

const int N = 1e6 + 10, mod = 1e9;
int n, f[N];

int main() {
  scanf("%d", &n);
  f[0] = 1;
  for (int i = 0; 1 << i <= n; i++)
    for (int j = 1 << i; j <= n; j++)
      f[j] = (f[j] + f[j - (1 << i)]) % mod;

  printf("%d\n", f[n]); 
}