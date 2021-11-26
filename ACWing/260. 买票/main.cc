#include <iostream>
using namespace std;

const int N = 2e5 + 5;
int tr[N], p[N], v[N], res[N];
int n;

int lowbit(int x) {
    return x & -x;
}

void add(int k, int x) {
    for (int i = k; i <= n; i += lowbit(i)) tr[i] += x;
}

int sum(int k) {
    int res = 0;
    for (int i = k; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &p[i], &v[i]);
            tr[i] = lowbit(i);
        }

        for (int i = n; i; i--) {
            int k = p[i] + 1;
            int l = 1, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (sum(mid) >= k) r = mid;
                else l = mid + 1;
            }

            res[l] = i;
            add(l, -1);
        }

        for (int i = 1; i <= n; i++) printf("%d ", v[res[i]]);
        puts("");
    }

    return 0;
}