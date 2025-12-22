#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 5e4 + 10, M = 2e5 + 10, FULL = (1 << 5) - 1;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int mp[N];
int dist[N][FULL + 1];
bool vis[N][FULL + 1];

struct State {
  int d, u, re;
  State(int d, int u, int re) : d(d), u(u), re(re) {}
};

int main() {
  scanf("%d%d", &n, &m);
  memset(mp, -1, sizeof mp);
  for (int i = 0; i < 5; i++) {
    int q;
    scanf("%d", &q);
    mp[q] = i;
  }
  memset(h, -1, sizeof h);
  auto add = [&](int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
  };
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    add(a, b, c), add(b, a, c);
  }

  auto dijkstra = [&]() {
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;
    auto cmp = [&](auto &s1, auto &s2) { return s1.d > s2.d; };
    priority_queue<State, vector<State>, decltype(cmp)> heap(cmp);
    heap.emplace(0, 1, 0);
    while (heap.size()) {
      auto [d, u, re] = heap.top();
      heap.pop();
      if (re == FULL)
        return dist[u][re];
      if (vis[u][re])
        continue;
      vis[u][re] = true;
      for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i], c = w[i];
        int nre = re;
        if (~mp[v])
          nre |= 1 << mp[v];
        if (dist[v][nre] > dist[u][re] + c) {
          dist[v][nre] = dist[u][re] + c;
          heap.emplace(dist[v][nre], v, nre);
        }
      }
    }
    return -1;
  };

  printf("%d\n", dijkstra());
}