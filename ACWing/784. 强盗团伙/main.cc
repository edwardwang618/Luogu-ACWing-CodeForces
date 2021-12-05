#include <iostream>
using namespace std;

const int N = 1010;
int n, m;
int p[N], e[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        char op[2];
        int _p, _q;
        scanf("%s%d%d", op, &_p, &_q);
        int pp = find(_p), pq = find(_q);
        if (*op == 'F') p[pp] = pq;
        else {
            if (e[_p]) p[pq] = find(e[_p]);
            else e[_p] = _q;
            if (e[_q]) p[pp] = find(e[_q]);
            else e[_q] = _p;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) if (p[i] == i) res++;
    printf("%d\n", res);

    return 0;
}