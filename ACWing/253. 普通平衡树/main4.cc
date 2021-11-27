#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int tr[N], op[N], v[N], a[N];
int sz, idx;

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

int get(int x) {
    return lower_bound(a + 1, a + 1 + idx, x) - a;
}

void insert(int x) {
    add(x, 1);
}

void remove(int x) {
    add(x, -1);
}

int get_rank_by_key(int x) {
    return sum(x - 1) + 1;
}

int get_key_by_rank(int rk) {
    int l = 1, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (sum(mid) >= rk) r = mid;
        else l = mid + 1;
    }

    return a[l];
}

int get_prev(int x) {
    return get_key_by_rank(sum(x - 1));
}

int get_next(int x) {
    return get_key_by_rank(sum(x) + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &op[i], &v[i]);
        if (op[i] != 4) a[++idx] = v[i];
    }

    sort(a + 1, a + 1 + idx);
    sz = unique(a + 1, a + 1 + idx) - (a + 1);

    for (int i = 1; i <= n; i++) {
        int opt = op[i], x = v[i];
        if (opt != 4) x = get(v[i]);

        if (opt == 1) insert(x);
        else if (opt == 2) remove(x);
        else if (opt == 3) printf("%d\n", get_rank_by_key(x));
        else if (opt == 4) printf("%d\n", get_key_by_rank(x));
        else if (opt == 5) printf("%d\n", get_prev(x));
        else if (opt == 6) printf("%d\n", get_next(x));
    }

    return 0;
}