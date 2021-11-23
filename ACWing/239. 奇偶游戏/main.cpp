#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 1e4 + 10;
int n, m;
int p[N], d[N];
unordered_map<int, int> mp;

int get(int x) {
    if (!mp.count(x)) mp[x] = ++n;
    return mp[x];
}

int find(int x) {
    if (p[x] != x) {
        int root = find(p[x]);
        d[x] ^= d[p[x]];
        p[x] = root;
    }

    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= N; i++) p[i] = i;

    n = 0;
    
    int res = m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        char type[5];
        scanf("%d%d%s", &a, &b, type);
        a = get(a - 1), b = get(b);

        int t = 0;
        if (type[0] == 'o') t = 1;

        int pa = find(a), pb = find(b);
        if (pa == pb) {
            if ((d[a] ^ d[b]) != t) {
                res = i - 1;
                break;
            }
        } else {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ t;
        }
    }

    printf("%d\n", res);

    return 0;
}