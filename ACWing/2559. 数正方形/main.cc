#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int n;

int main() {
  scanf("%d", &n);
  int res = 0;
  for (int i = 1; i <= n; i++)
    res = (res + (long)(n - i) * (n - i) * i) % MOD;

  printf("%d\n", res);
}