#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int p[N], idx;
bool st[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (!st[i]) p[idx++] = i;
    for (int j = 0; p[j] * i < N; j++) {
      st[p[j] * i] = true;
      if (i % p[j] == 0) break;
    }
  }

  int n;
  while (cin >> n, n) {
    for (int i = 1;; i++) {
      if (!st[n - p[i]]) {
        printf("%d = %d + %d\n", n, p[i], n - p[i]);
        break;
      }
    }
  }
}