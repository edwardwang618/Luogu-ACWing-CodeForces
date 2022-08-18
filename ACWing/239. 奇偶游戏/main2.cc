#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = (1e4 + 10) * 2, M = 1e4 + 10;
int n, m;
int p[N];
unordered_map<int, int> mp;

int get(int x) {
    if (!mp.count(x)) mp[x] = ++n;
    return mp[x];
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < N; i++) p[i] = i;

    n = 0;
    
    int res = m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        char type[5];
        scanf("%d%d%s", &a, &b, type);
        a = get(a - 1), b = get(b);

        if (type[0] == 'e') {
            if (find(a) == find(b + M)) {
                res = i - 1;
                break;
            }
            p[find(a)] = find(b);
            p[find(a + M)] = find(b + M);
        } else {
            if (find(a) == find(b)) {
                res = i - 1;
                break;
            }
            p[find(a)] = find(b + M);
            p[find(a + M)] = find(b);
        }
    }

    printf("%d\n", res);

    return 0;
}