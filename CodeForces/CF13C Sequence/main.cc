#include <iostream>
#include <queue>
using namespace std;
using LL = long long;

const int N = 5010;
int n, a[N];

LL solve() {
  LL res = 0;
  priority_queue<int> heap;
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
  printf("%lld\n", solve());
}