#include <iostream>
#include <algorithm>
#include <cmath>

#define l first
#define r second

using namespace std;
using PII = pair<int, int>;

const int N = 40005, T = 205;
PII b[T];
int n, m, sz, cnt, len;
int a[N], lsh[N], blk[N], t[N];
int s[T][N], f[T][T];
int res;

int getval(int x) {
    return lower_bound(lsh + 1, lsh + 1 + len, x) - lsh;
}

void init() {
    cnt = n / sz;
    if (n % sz) cnt++;
    for (int i = 1; i <= cnt; i++) b[i] = {(i - 1) * sz + 1, i * sz};
    b[cnt].r = n;

    for (int i = 1; i <= cnt; i++) {
        int l = b[i].l, r = b[i].r;
        for (int j = l; j <= r; j++) s[i][a[j]]++, blk[j] = i;
        for (int j = 1; j <= len; j++) s[i][j] += s[i - 1][j];
    }

    for (int i = 1; i <= cnt; i++)
        for (int j = i; j <= cnt; j++) {
            int mode = f[i][j - 1];
            for (int k = b[j].l; k <= b[j].r; k++) {
                int v1 = s[j][a[k]] - s[i - 1][a[k]], v2 = s[j][mode] - s[i - 1][mode];
                if (v1 > v2) mode = a[k];
                else if (v1 == v2) mode = min(mode, a[k]);
            }

            f[i][j] = mode;
        }
}

int incomp_block(int l, int r, int L, int R, int mode) {
    for (int i = l; i <= r; i++) {
        int v1 = t[a[i]] + s[blk[R] - 1][a[i]] - s[blk[L]][a[i]];
        int v2 = t[mode] + s[blk[R] - 1][mode] - s[blk[L]][mode];
        if (v1 > v2) mode = a[i];
        else if (v1 == v2) mode = min(mode, a[i]);
    }

    return mode;
}

int one_block(int l, int r) {
    for (int i = l; i <= r; i++) t[a[i]]++;
    int mode = a[l];
    for (int i = l + 1; i <= r; i++)
        if (t[a[i]] > t[mode]) mode = a[i];
        else if (t[a[i]] == t[mode]) mode = min(mode, a[i]);
    for (int i = l; i <= r; i++) t[a[i]] = 0;
    return lsh[mode];
}

int solve(int l, int r) {
    if (blk[r] - blk[l] <= 1) return one_block(l, r);
    for (int i = l; i <= b[blk[l]].r; i++) t[a[i]]++;
    for (int i = b[blk[r]].l; i <= r; i++) t[a[i]]++;
    int mode = f[blk[l] + 1][blk[r] - 1];
    mode = incomp_block(l, b[blk[l]].r, l, r, mode);
    mode = incomp_block(b[blk[r]].l, r, l, r, mode);
    for (int i = l; i <= b[blk[l]].r; i++) t[a[i]] = 0;
    for (int i = b[blk[r]].l; i <= r; i++) t[a[i]] = 0;
    return lsh[mode];
}

int main() {
    scanf("%d%d", &n, &m);
    sz = sqrt(n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = lsh[i] = x;
    }

    sort(lsh + 1, lsh + 1 + n);
    len = unique(lsh + 1, lsh + 1 + n) - (lsh + 1);
    for (int i = 1; i <= n; i++) a[i] = getval(a[i]);
    init();
    for (int i = 1; i <= m; i++) {
        int ll, rr;
        scanf("%d%d", &ll, &rr);
        int l = (ll + res - 1) % n + 1, r = (rr + res - 1) % n + 1;
        if (l > r) swap(l, r);
        printf("%d\n", res = solve(l, r));
    }

    return 0;
}