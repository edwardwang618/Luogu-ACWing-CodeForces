#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n, q, m;
int a[N];
vector<int> pos[N];

int get_next(int x, int i) {
    if (!pos[x].size()) return 0;

    int l = 0, r = pos[x].size() - 1;
    while (l < r) {
        int mid = l + (r - l >> 1);
        if (pos[x][mid] > i) r = mid;
        else l = mid + 1;
    }

    return pos[x][l] > i ? pos[x][l] : 0;
}

int main() {
    int type;
    scanf("%d%d%d%d", &type, &n, &q, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]].push_back(i);
    }

    while (q--) {
        int len;
        scanf("%d", &len);
        bool success = true;
        int cur = 0;
        while (len--) {
            int x;
            scanf("%d", &x);
            cur = get_next(x, cur);
            if (!cur || !success) success = false;
        }

        if (success) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}