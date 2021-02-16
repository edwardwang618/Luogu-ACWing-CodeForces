#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> PII;

const int N = 200010, INF = 0x3f3f3f3f;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int cnt;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int prim() {
    memset(dist, 0x3f, sizeof dist);
    
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({INF, 1});
    dist[1] = 0;

    int res = 0;
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int v = t.second, c = t.first;

        if (st[v]) continue;

        if (v != 1) {
            res += c;
            cnt++;
            if (cnt == n - 1) break;
        }

        st[v] = true;

        for (int i = h[v]; i != -1; i = ne[i]) {
            int j = e[i], c = w[i];
            if (!st[j] && dist[j] > c) {
                dist[j] = c;
                heap.push({c, j});
            }
        }
    }

    return cnt < n - 1 ? INF : res;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a == b) continue;
        add(a, b, c), add(b, a, c);
    }

    int t = prim();

    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}