#include <iostream>
#include <cstring>
using namespace std;

const int N = 310;
int n, m;
int g[N][N], dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;

    int res = 0;
    for (int i = 0; i <= n; i++) {
        int t = -1;
        for (int j = 0; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        
        st[t] = true;
        res += dist[t];
        
        for (int j = 0; j <= n; j++)
            if (!st[j]) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g[0][i]);
        g[i][0] = g[0][i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            g[j][i] = g[i][j];
        }

    cout << prim() << endl;

    return 0;
}