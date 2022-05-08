#include <iostream>
#include <cstring>
using namespace std;

const int N = 100100, M = 400100;
int h[N], e[M], ne[M], idx;
int res[M], cnt;
bool used[M];
int din[N], dout[N];
int n, m;
int type;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u) {
    for(int i = h[u]; ~i ;i = h[u]) {
        if (used[i]) {
            h[u] = ne[i];
            continue;
        }

        // used[i] = true;
        // 如果是无向图，那么这条边的反向边也要标记使用过了
        if (type == 1) used[i ^ 1] = true;

        int t;
        if (type == 1) {
            t = i / 2 + 1;
            // (0, 1) (2, 3) (4, 5)奇数编号是返回的边
            if (i & 1) t = -t;
        } else t = i + 1;

        int v = e[i];
        h[u] = ne[i];
        dfs(v);
        res[cnt++] = t;
    }
}

int main() {
    scanf("%d%d%d", &type, &n, &m);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        // 无向边
        if (type == 1) add(b, a);
        din[b]++, dout[a]++;   
    }

    if (type == 1) {
        for (int i = 1; i <= n; i++)
            if (din[i] + dout[i] & 1) {
                //无向图含欧拉回路的充要条件是每个点的度都为偶数
                puts("NO");
                return 0;
            }
    } else {
        for (int i = 1; i <= n; i++)
            if (din[i] != dout[i]) {
                //有向图含欧拉回路的充要条件是每个点的入度等于出度
                puts("NO");
                return 0;
            }
    }

    for (int i = 1; i <= n; i++) 
        if (~h[i]) {
            dfs(i);
            break;
        }

    if (cnt < m) puts("NO");
    else {
        puts("YES");
        for (int i = cnt - 1; i >= 0; i--)
            printf("%d ", res[i]);
    }

    return 0;
}