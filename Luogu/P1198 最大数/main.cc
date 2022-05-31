#include <iostream>
#include <cmath>
using namespace std;

const int N = 2e5 + 10;
int n, idx;
long f[N][20], D;

long query(int c) {
  int k = log2(c);
  return max(f[idx][k], f[idx - c + (1 << k)][k]);
}

void add(long x) {
  f[idx + 1][0] = x;
  for (int k = 1; 1 << k <= idx + 1; k++)
    f[idx + 1][k] = max(x, query((1 << k) - 1));
  idx++;
}

int main() {
  scanf("%d%ld", &n, &D);
  long t = 0, c;
  char op;
  while (n--) {
    cin >> op >> c;
    if (op == 'A') add((t + c) % D);
    else printf("%ld\n", t = query(c));
  }
}