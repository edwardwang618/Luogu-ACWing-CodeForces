#include <iostream>
#include <stack>
using namespace std;

const int N = 1e6 + 10;
int n;
int h[N], v[N];
int sum[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &h[i], &v[i]);

  stack<int> stk;
  for (int i = 1; i <= n; i++) {
    while (stk.size() && h[stk.top()] < h[i]) {
      sum[i] += v[stk.top()];
      stk.pop();
    }
    if (stk.size()) sum[stk.top()] += v[i];
    stk.push(i);
  }

  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, sum[i]);
  printf("%d\n", res);
}