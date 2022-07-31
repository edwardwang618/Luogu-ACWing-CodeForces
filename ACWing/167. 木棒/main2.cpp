#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 70;
int n;
int a[N], len, sum;
// s[i]是第i组已经拼出的长度，g[i]是下标为i的小木棍放在了的组的下标
int s[N], g[N];

// u是当前枚举到了的小木棍的下标，cnt是已经有多少个非空组
bool dfs(int u, int cnt) {
  // 如果枚举完了，看一下cnt是否是sum / len，
  // 如果是，说明得出了一个解，返回true
  if (u == n) {
    return cnt * len == sum;
  }

  // 如果开的组数过大，说明无解，返回false
  if (cnt > sum / len) return false;

  int start = 0;
  // 如果当前小木棍和上一个小木棍等长，则其从上一个小木棍所在组及其之后开始枚举
  if (u && a[u] == a[u - 1]) start = g[u - 1];

  for (int i = start; i <= cnt; i++) {
    if (s[i] + a[u] > len) continue;

    s[i] += a[u];
    g[u] = i;
    if (dfs(u + 1, cnt + (i == cnt ? 1 : 0))) return true;
    s[i] -= a[u];

    // 如果a[u]放在首尾无解，则该分支无解
    if (!s[i] || s[i] + a[u] == len) return false;
  }

  return false;
}

int main() {
  while (cin >> n, n) {
    sum = len = 0;
    memset(s, 0, sizeof s);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }

    sort(a, a + n, greater<int>());
    for (len = a[0]; len <= sum; len++)
      if (sum % len == 0 && dfs(0, 0)) {
        printf("%d\n", len);
        break;
      }
  }

  return 0;
}
