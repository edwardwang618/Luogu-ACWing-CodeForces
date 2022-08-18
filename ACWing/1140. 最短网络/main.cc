#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int n;
int a[N][N];
int dist[N];
bool st[N];

int prim() {
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j])) 
                t = j;

        res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j++)
            if (!st[j] && dist[j] > a[t][j])
                dist[j] = a[t][j];
    }

    return res;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    cout << prim() << endl;

    return 0;
}