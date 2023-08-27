#include <iostream>
using namespace std;

const int N = 2e5 + 10;
int n;
char s[N];

int dfs(int l, int r, char x) {
  if (l == r) return x == s[l] ? 0 : 1;
  int mid = l + (r - l >> 1);
  int y1 = 0, y2 = 0;
  for (int i = l; i <= mid; i++)
    if (s[i] != x) y1++;
  for (int i = mid + 1; i <= r; i++)
    if (s[i] != x) y2++;

  return min(y1 + dfs(mid + 1, r, x + 1), y2 + dfs(l, mid, x + 1));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%s", &n, s);
    printf("%d\n", dfs(1, n, 'a'));
  }
}