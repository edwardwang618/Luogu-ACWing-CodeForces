# include<iostream>
# include<cstring>
using namespace std;

const int N = 600010, M = N * 25, POS = 23;
int n, m;
int s[N];
int tr[M][2], max_id[M];
int root[N], idx;

void insert(int k, int p, int q) {
    for (int i = POS; i >= 0; i--) {
        int v = s[k] >> i & 1;

        if (p) tr[q][v ^ 1] = tr[p][v ^ 1];
        tr[q][v] = ++idx;
        p = tr[p][v], q = tr[q][v];
        max_id[q] = k;
    }
}

int query(int root, int C, int L) {
    int p = root;
    for (int i = POS; i >= 0; i--) {
        int v = C >> i & 1;
        if (max_id[tr[p][v ^ 1]] >= L) p = tr[p][v ^ 1];
        else p = tr[p][v];
    }

    return C ^ s[max_id[p]];
}

int main() {
    scanf("%d%d", &n, &m);

    max_id[0] = -1;
    root[0] = ++idx;
    insert(0, 0, root[0]);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;
        root[i] = ++idx;
        insert(i, root[i - 1], root[i]);
    }

    char op[2];
    int l, r, x;
    while (m--) {
        scanf("%s", op);
        if (*op == 'A') {
            scanf("%d", &x);
            n++;
            s[n] = s[n - 1] ^ x;
            root[n] = ++idx;
            insert(n, root[n - 1], root[n]);
        } else {
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(root[r - 1], s[n] ^ x, l - 1));
        }
    }

    return 0;
}