#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int n, m;
struct Node {
    int s[2], p, v, id;
    int sz;
    void init(int _v, int _id, int _p) {
        v = _v, id = _id, p = _p;
        sz = 1;
    }
} tr[N];
int root[N], idx;
int p[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void pushup(int x) {
    tr[x].sz = tr[tr[x].s[0]].sz + tr[tr[x].s[1]].sz + 1;
}

void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x, int k, int b) {
    while (tr[x].p != k) {
        int y = tr[x].p, z = tr[y].p;
        if (z != k)
            if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y)) rotate(x);
            else rotate(y);
        rotate(x);
    }

    if (!k) root[b] = x;
}

void insert(int u, int b) {
    int c = root[b], v = tr[u].v, p = 0;
    while (c) p = c, c = tr[c].s[v > tr[c].v];
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].p = p;
    splay(u, 0, b);
}

int get_k(int k, int b) {
    int u = root[b];
    while (u) {
        if (k <= tr[tr[u].s[0]].sz) u = tr[u].s[0];
        else if (k > tr[tr[u].s[0]].sz + 1) {
            k -= tr[tr[u].s[0]].sz + 1;
            u = tr[u].s[1];
        } else return tr[u].id;
    }

    return -1;
}

void dfs(int u, int b) {
    if (!u) return;

    if (tr[u].s[0]) dfs(tr[u].s[0], b);
    if (tr[u].s[1]) dfs(tr[u].s[1], b); 
    insert(u, b);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        p[i] = root[i] = i;
        int v;
        scanf("%d", &v);
        tr[i].init(v, i, 0);
    }
    idx = n;

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if (a != b) {
            if (tr[root[a]].sz > tr[root[b]].sz) swap(a, b);
            p[a] = b;
            dfs(root[a], b);
        }
    }

    scanf("%d", &m);
    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        a = find(a);
        if (*op == 'B') {
            b = find(b);
            if (a != b) {
                if (tr[root[a]].sz > tr[root[b]].sz) swap(a, b);
                p[a] = b;
                dfs(root[a], b);
            }
        } else {
            if (tr[root[a]].sz < b) puts("-1");
            else printf("%d\n", get_k(b, a));
        }
    }

    return 0;
}