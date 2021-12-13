#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 2510, M = 6200 * 2 + 10;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int s, ed;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &ed);
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    priority_queue<PII, vector<PII>, greater<>> heap;
    dist[s] = 0;
    heap.push({0, s});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int v = t.second, d = t.first;
        if (v == ed) {
            printf("%d\n", d);
            break;
        }

        st[v] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j] && dist[j] > dist[v] + w[i]) {
                dist[j] = dist[v] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    return 0;
}