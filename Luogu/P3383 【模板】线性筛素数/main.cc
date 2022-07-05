#include <iostream>
using namespace std;

const int N = 1e8 + 10;
int n, q;
int p[N], cnt;
bool st[N];

void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) p[++cnt] = i;
    for (int j = 1; p[j] <= n / i; j++) {
      st[p[j] * i] = true;
      if (i % p[j] == 0) break;
    }
  }
}

int main() {
  scanf("%d%d", &n, &q);
  get_primes(n);
  while (q--) {
    int x;
    scanf("%d", &x);
    printf("%d\n", p[x]);
  }
}