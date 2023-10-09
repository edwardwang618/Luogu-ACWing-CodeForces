#include <iostream>
#include <queue>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int a[N], u;
priority_queue<int, vector<int>, greater<>> min_heap;
priority_queue<int> max_heap;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1, j = 1; i <= m; i++) {
    scanf("%d", &u);
    while (j <= u) {
      max_heap.push(a[j++]);
      if (max_heap.size() > i) min_heap.push(max_heap.top()), max_heap.pop();
    }

    printf("%d\n", max_heap.top());
    if (min_heap.size()) max_heap.push(min_heap.top()), min_heap.pop();
  }
}