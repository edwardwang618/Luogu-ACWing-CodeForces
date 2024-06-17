#include <cstring>
#include <iostream>
using namespace std;

const int N = 1010;
int n, m, k;
int a[N];

int main() {
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    memset(a, 0, sizeof a);
    while (m--) {
      int x;
      scanf("%d", &x);
      int l = max(1, x - k), r = min(n, x + k);
      a[l]++, a[r + 1]--;
    }

    int res = 0;
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
      if (!a[i]) {
        int j = i;
        while (j <= n && !a[j]) j++;
        res += (j - i + 2 * k) / (2 * k + 1);
        i = j - 1;
      }
    printf("%d\n", res);
  }
}