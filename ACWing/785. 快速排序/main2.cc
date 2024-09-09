#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];
int tmp[N], cnt[15];

void radix_sort(int M) {
  for (int rad = 1; rad <= M; rad *= 10) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 1; i <= n; i++) cnt[a[i] / rad % 10]++;
    for (int i = 1; i < 10; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i; i--) tmp[cnt[a[i] / rad % 10]--] = a[i];
    for (int i = 1; i <= n; i++) a[i] = tmp[i];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  radix_sort(*max_element(a + 1, a + 1 + n));
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}