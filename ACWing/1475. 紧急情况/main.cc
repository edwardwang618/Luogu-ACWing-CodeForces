#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
using PII = pair<int, int>;

const int N = 510, M = 1210;
int n, m;
int c1, c2;
int h[N], e[M], ne[M], w[M], idx;
int resc[N];
int dist[N], cnt[N], sum[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int main() {
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);

    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    c1++, c2++;
    for (int i = 1; i <= n; i++) scanf("%d", &resc[i]);
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a++, b++;
        add(a, b, c), add(b, a, c);
    }
    
    dist[c1] = 0;
    cnt[c1] = 1;
    sum[c1] = resc[c1];
    priority_queue<PII, vector<PII>, greater<>> heap;
    heap.push({0, c1});
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int v = t.second, d = t.first;
        if (v == c2) break;

        if (st[v]) continue;
        st[v] = true;
        for (int i = h[v]; ~i; i = ne[i]) {
            int j = e[i];
            if (st[j]) continue;
            if (dist[j] > dist[v] + w[i]) {
                dist[j] = dist[v] + w[i];
                cnt[j] = cnt[v];
                sum[j] = sum[v] + resc[j];
                heap.push({dist[j], j});
            } else if (dist[j] == dist[v] + w[i]) {
                cnt[j] += cnt[v];
                sum[j] = max(sum[j], sum[v] + resc[j]);
            }
        }
    }

    printf("%d %d\n", cnt[c2], sum[c2]);

    return 0;
}