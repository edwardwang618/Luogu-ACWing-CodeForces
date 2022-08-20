#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 2010;
int n, a[N];

int work() {
  priority_queue<int> heap;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    heap.push(a[i]);
    if (a[i] < heap.top()) {
      res += heap.top() - a[i];
      heap.pop();
      heap.push(a[i]);
    }
  }

  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  int res = work();
  reverse(a + 1, a + 1 + n);
  res = min(res, work());
  printf("%d\n", res);
}