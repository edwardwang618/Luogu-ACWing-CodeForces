#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010, M = 300010;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
long dist[N];
int stk[N], top, cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa() {
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    stk[top++] = 0;
    st[0] = true;
    
    while (top) {
        int t = stk[--top];
        st[t] = false;
        
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (dist[v] < dist[t] + w[i]) {
                dist[v] = dist[t] + w[i];
                cnt[v] = cnt[t] + 1;
                if (cnt[v] > n) return false;

                if (!st[v]) {
                    stk[top++] = v;
                    st[v] = true;
                }
            }
        }
    }

    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while (m--) {
        int x, a, b;
        scanf("%d%d%d", &x, &a, &b);
        if (x == 1) add(b, a, 0), add(a, b, 0);
        else if (x == 2) add(a, b, 1);
        else if (x == 3) add(b, a, 0);
        else if (x == 4) add(b, a, 1);
        else add(a, b, 0);
    }

    for (int i = 1; i <= n; i++) add(0, i, 1);
    
    if (!spfa()) puts("-1");
    else {
        long res = 0;
        for (int i = 1; i <= n; i++) res += dist[i];
        printf("%ld\n", res);
    }

    return 0;
}