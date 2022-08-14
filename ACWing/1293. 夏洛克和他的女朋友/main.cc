#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n;
int p[N], idx;
bool st[N];

int main() {
  scanf("%d", &n);

  for (int i = 2; i <= n + 1; i++) {
    if (!st[i]) p[idx++] = i;
    for (int j = 0; i * p[j] <= n + 1; j++) {
      st[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }

  n <= 2 ? puts("1") : puts("2");
  for (int i = 2; i <= n + 1; i++)
    if (!st[i]) printf("1 ");
    else printf("2 ");
}