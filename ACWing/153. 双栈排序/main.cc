#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

const int N = 1010;
int n;
int a[N], f[N];
int col[N];
bool g[N][N];

bool dfs(int u, int c) {
  col[u] = c;
  for (int i = 1; i <= n; i++)
    if (g[u][i]) {
      if (c == col[i])
        return false;
      if (!~col[i] && !dfs(i, !c))
        return false;
    }
  return true;
}

int main() {
  memset(g, 0, sizeof g);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]);
  f[n + 1] = n + 1;
  for (int i = n; i; i--)
    f[i] = min(a[i], f[i + 1]);

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (a[i] < a[j] && f[j + 1] < a[i])
        g[i][j] = g[j][i] = true;

  memset(col, -1, sizeof col);
  bool flag = true;
  for (int i = 1; i <= n; i++)
    if (!~col[i] && !dfs(i, 0)) {
      flag = false;
      break;
    }
  if (!flag) {
    puts("0");
    return 0;
  }

  string res;
  stack<int> stk1, stk2;
  int cur = 1;
  int j = 1;
  for (int i = 1; i <= 2 * n; i++) {
    if (j <= n && !col[j] && (stk1.empty() || stk1.top() > a[j])) {
      stk1.push(a[j]);
      j++;
      printf("a ");
    } else if (stk1.size() && stk1.top() == cur) {
      stk1.pop();
      printf("b ");
      cur++;
    } else if (j <= n && col[j] && (stk2.empty() || stk2.top() > a[j])) {
      stk2.push(a[j]);
      j++;
      printf("c ");
    } else if (stk2.size() && stk2.top() == cur) {
      stk2.pop();
      printf("d ");
      cur++;
    }
  }
}