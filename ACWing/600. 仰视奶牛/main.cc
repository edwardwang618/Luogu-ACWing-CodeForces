#include <iostream>
#include <stack>

#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
int n, a[N], res[N];
stack<pair<int, int>> stk;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    while (stk.size() && stk.top().y < x) {
      auto t = stk.top();
      stk.pop();
      res[t.x] = i;
    }
    stk.push({i, x});
  }
  for (int i = 1; i <= n; i++) printf("%d\n", res[i]);
}