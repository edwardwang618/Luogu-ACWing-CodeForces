#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], res[N];
int tr[N];

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
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i++) tr[i] = lowbit(i);

    for (int i = n; i; i--) {
        int k = a[i] + 1;
        int l = 1, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (sum(mid) >= k) r = mid;
            else l = mid + 1;
        }

        res[i] = l;
        add(l, -1);
    }

    for (int i = 1; i <= n; i++) printf("%d\n", res[i]);
    return 0;
}