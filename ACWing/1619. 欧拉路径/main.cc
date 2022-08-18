#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int n, m;
int p[N], d[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    int group = n;

    for (int i = 1; i <= n; i++) p[i] = i;
    
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        d[a]++, d[b]++;
        int pa = find(a), pb = find(b);
        if (pa != pb) {
            p[pa] = pb;
            group--;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", d[i]);
    printf("\n");
    
    if (group > 1) printf("Non-Eulerian\n");
    else {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (d[i] % 2) cnt++;
        }

        if (!cnt) printf("Eulerian\n");
        else if (cnt == 2) printf("Semi-Eulerian\n");
        else printf("Non-Eulerian\n");
    }

    return 0;
}