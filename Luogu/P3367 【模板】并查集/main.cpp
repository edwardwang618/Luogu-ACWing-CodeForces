#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e4 + 10, M = 2e5 + 10;
int n, m;
int p[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) p[i] = i;
    while (m--) {
        int a, b, op;
        cin >> op >> a >> b;
        int pa = find(a), pb = find(b);
        if (op == 1) p[pa] = pb;
        else if (op == 2) printf("%s\n", pa == pb ? "Y" : "N");
    }

    return 0;
}