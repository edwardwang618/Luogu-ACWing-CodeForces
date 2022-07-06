#include <iostream>
using namespace std;

const int N = 3e6 + 10;
long inv[N];

int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  inv[1] = 1;
  puts("1");
  for (int i = 2; i <= n; i++)
    printf("%ld\n", inv[i] = (long)p - (p / i) * inv[p % i] % p);
}