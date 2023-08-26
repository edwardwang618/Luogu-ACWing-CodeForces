#include <iostream>
#include <stack>
using namespace std;

const int N = 1010;
int m, n;
int a[N][N];
int res;

int calc(int a[]) {
  int res = 0;
  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    while (stk.size() && a[stk.top()] > a[i]) {
      int t = a[stk.top()]; stk.pop();
      int l = stk.size() ? stk.top() : 0, r = i;
      res = max(res, t * (r - l - 1));
    }

    stk.push(i);
  }

  while (stk.size()) {
    int t = a[stk.top()]; stk.pop();
    int l = stk.size() ? stk.top() : 0, r = n + 1;
    res = max(res, t * (r - l - 1));
  }

  return res;
}

int main() {
  cin >> m >> n;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      char ch;
      cin >> ch;
      if (ch == 'F') a[i][j] = 1;
    }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++)
      if (a[i][j]) a[i][j] += a[i - 1][j];
    res = max(res, calc(a[i]));
  }

  printf("%d\n", 3 * res);
}