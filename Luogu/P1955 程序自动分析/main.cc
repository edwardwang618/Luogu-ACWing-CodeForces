#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1e6 + 10;
int n, idx, k;
int p[N];
unordered_map<int, int> mp;
pair<int, int> a[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i < N; i++) p[i] = i;
        idx = k = 0;
        mp.clear();

        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x, y, e;
            scanf("%d%d%d", &x, &y, &e);
            if (!mp.count(x)) mp[x] = ++k;
            if (!mp.count(y)) mp[y] = ++k;
            x = mp[x];
            y = mp[y];

            if (e == 1) p[find(x)] = find(y);
            else a[++idx] = {x, y};
        }

        bool flag = true;
        for (int i = 1; i <= idx; i++)
            if (find(a[i].first) == find(a[i].second)) {
                flag = false;
                break;
            }

        if (flag) puts("YES");
        else puts("NO");
    }

    return 0;
}