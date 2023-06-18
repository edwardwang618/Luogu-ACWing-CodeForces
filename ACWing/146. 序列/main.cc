#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 2010, M = 1010;
int m, n;
int a[M][N], c[N];
bool vis[N][N];
struct Node {
  int y1, y2, sum;
};
auto comp = [](Node& p1, Node& p2) { return p1.sum > p2.sum; };

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &m, &n);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
      sort(a[i] + 1, a[i] + 1 + n);
    }
    for (int i = 2; i <= m; i++) {
      priority_queue<Node, vector<Node>, decltype(comp)> heap(comp);
      memset(vis, 0, sizeof(vis));
      heap.push({1, 1, a[1][1] + a[i][1]});
      for (int j = 1; j <= n; j++) {
        auto t = heap.top(); heap.pop();
        c[j] = t.sum;
        int y1 = t.y1, y2 = t.y2;
        if (y1 + 1 <= n && !vis[y1 + 1][y2]) {
          heap.push({y1 + 1, y2, a[1][y1 + 1] + a[i][y2]});
          vis[y1 + 1][y2] = true;
        }
        if (y2 + 1 <= n && !vis[y1][y2 + 1]) {
          heap.push({y1, y2 + 1, a[1][y1] + a[i][y2 + 1]});
          vis[y1][y2 + 1] = true;
        }
      }

      for (int j = 1; j <= n; j++) a[1][j] = c[j];
    }

    for (int i = 1; i <= n; i++) printf("%d ", a[1][i]);
    puts("");
  }
}