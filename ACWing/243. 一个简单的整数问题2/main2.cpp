#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100010, M = 350;
int n, m, len;
long add[M], sum[M];
int w[N];

int get(int i) {
    return i / len;
}

void change(int l, int r, int d) {
    if (get(l) == get(r)) {
        for (int i = l; i <= r; i++) w[i] += d, sum[get(i)] += d;
    } else {
        int i = l, j = r;
        while (get(i) == get(l)) w[i] += d, sum[get(i)] += d, i++;
        while (get(j) == get(r)) w[j] += d, sum[get(j)] += d, j--;
        for (int k = get(i); k <= get(j); k++) sum[k] += len * d, add[k] += d;
    }
}

long query(int l, int r) {
    long res = 0;
    if (get(l) == get(r)) {
        for (int i = l; i <= r; i++) res += w[i] + add[get(i)];
    } else {
        int i = l, j = r;
        while (get(i) == get(l)) res += w[i] + add[get(i)], i++;
        while (get(j) == get(r)) res += w[j] + add[get(j)], j--;
        for (int k = get(i); k <= get(j); k++) res += sum[k];
    }
    
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    len = sqrt(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        sum[get(i)] += w[i];
    }

    char op[2];
    int l, r, d;
    while (m--) {
        scanf("%s%d%d", op, &l, &r);
        if (op[0] == 'C') {
            scanf("%d", &d);
            change(l, r, d);
        } else printf("%ld\n", query(l, r));
    }

    return 0;
}