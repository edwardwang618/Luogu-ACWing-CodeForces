#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 70;
int n;
int a[N], len, sum;
bool st[N];

// dfs的定义是，正在放第u组，第u组已经放了l的长度，从start开始枚举，问能否放完
// u是当前在放第几组，从0开始
// l是第u组已经放了多长，start是第u组在枚举哪个木棒的时候从哪个木棒开始枚举，那个木棒的下标
bool dfs(int u, int l, int start) {
  if (u * len == sum) return true;
  if (l == len) return dfs(u + 1, 0, 0);

  // 组合型枚举
  for (int i = start; i < n; i++) {
    if (st[i]) continue;
    if (l + a[i] > len) continue;
    if (i > start && !st[i - 1] && a[i] == a[i - 1]) continue;

    st[i] = true;
    if (dfs(u, l + a[i], i + 1)) return true;
    st[i] = false;

    if (!l || l + a[i] == len) return false;
  }

  return false;
}

int main() {
  while (cin >> n, n) {
    sum = len = 0;
    memset(st, 0, sizeof st);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    sort(a, a + n, greater<int>());
    for (len = a[0]; len <= sum; len++)
      if (sum % len == 0 && dfs(0, 0, 0)) {
        printf("%d\n", len);
        break;
      }
  }

  return 0;
}