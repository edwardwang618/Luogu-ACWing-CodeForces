#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 130;
int m;
int g[N][N];
int dist[N];
bool st[N];

int main() {
    memset(g, 0x3f, sizeof g);
    memset(dist, 0x3f, sizeof dist);

    scanf("%d\n", &m);
    while (m--) {
        char a, b;
        int c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    char res;
    dist['Z'] = 0;
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.push({0, 'Z'});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int v = t.second;
        if ('A' <= v && v < 'Z') {
            res = v;
            break;
        }

        if (st[v]) continue;
        st[v] = true;
        for (int i = 0; i <= 'z'; i++) {
            if (g[v][i] == 0x3f3f3f3f) continue;

            if (!st[i] && dist[i] > dist[v] + g[v][i]) {
                dist[i] = dist[v] + g[v][i];
                heap.push({dist[i], i});
            }
        }
    }

    printf("%c %d", res, dist[res]);

    return 0;
}