#include <iostream>

using namespace std;

const int N = 510, M = 2010;
int n, m;
int p[N], d[N], x[M], y[M], comp[M];

void init() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        d[i] = 0;
    }
}

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] = (d[x] + d[p[x]]) % 3;
        p[x] = root;
    }

    return p[x];
}

int main() {
    while (scanf("%d%d", &n, &m) != -1) {
        for (int i = 1; i <= m; i++) {
            char ch;
            scanf("%d%c%d", &x[i], &ch, &y[i]);
            if (ch == '<') comp[i] = 1;
            else if (ch == '=') comp[i] = 0;
            else comp[i] = 2;
        }

        int cnt = 0, judge = 0, line = 0;
        for (int k = 0; k < n; k++) {
            init();
            for (int i = 1; i <= m; i++) {
                int a = x[i], b = y[i], pa = find(a), pb = find(b);
                if (a != k && b != k) {
                    if (pa == pb) {
                        if ((d[a] - d[b] + 3) % 3 != comp[i]) {
                            line = max(line, i);
                            break;
                        }
                    } else {
                        p[pa] = pb;
                        d[pa] = (d[b] - d[a] + comp[i] + 3) % 3;
                    }
                }

                if (i == m) {
                    cnt++;
                    judge = k;
                }
            }
        }

        if (!m) cnt = n;
        
        if (cnt > 1) puts("Can not determine");
        else if (!cnt) puts("Impossible");
        else printf("Player %d can be determined to be the judge after %d lines\n", judge, line);
    }

    return 0;
}