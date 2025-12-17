#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int N = 5e4 + 10;
int n;
struct Cow {
  int id, l, r;
} cow[N];
int res[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cow[i].id = i;
    scanf("%d%d", &cow[i].l, &cow[i].r);
  }
  sort(cow + 1, cow + 1 + n, [&](auto &c1, auto &c2) { return c1.l < c2.l; });
  auto cmp = [&](auto &c1, auto &c2) { return c1.r > c2.r; };
  priority_queue<Cow, vector<Cow>, decltype(cmp)> heap(cmp);
  int id = 0;
  for (int i = 1; i <= n; i++) {
    auto &c = cow[i];
    if (heap.size() && heap.top().r < c.l) {
      auto ctop = heap.top();
      heap.pop();
      res[c.id] = res[ctop.id];
    } else
      res[c.id] = ++id;
    heap.push(c);
  }

  printf("%d\n", id);
  for (int i = 1; i <= n; i++)
    printf("%d\n", res[i]);
}