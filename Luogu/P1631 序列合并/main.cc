#include <iostream>
#include <queue>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

const int N = 1e5 + 10;
int n;
int a[N], b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

  auto cmp = [&](const PII& p1, const PII& p2) {
    int x1 = p1.x, y1 = p1.y;
    int x2 = p2.x, y2 = p2.y;
    return a[x1] + b[y1] > a[x2] + b[y2];
  };
  priority_queue<PII, vector<PII>, decltype(cmp)> heap(cmp);
  for (int i = 1; i <= n; i++) heap.push({i, 1});
  for (int i = 1; i <= n; i++) {
    auto t = heap.top(); heap.pop();
    printf("%d ", a[t.x] + b[t.y]);
    if (t.y + 1 <= n) heap.push({t.x, t.y + 1});
  }
}