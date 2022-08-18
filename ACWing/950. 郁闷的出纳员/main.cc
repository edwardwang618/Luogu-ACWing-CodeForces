#include <iostream>
using namespace std;

const int N = 1e5 + 10, INF = 1e9;
int n, m, delta;
struct Node {
    int s[2], p, v;
    int size;
    void init(int _v, int _p) {
        v = _v;
        p = _p;
        size = 1;
    }
} tr[N];
int root, idx;

void pushup(int x) {
    tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
}

void rotate(int x) {
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[y == tr[z].s[1]] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}

void splay(int x, int g) {
    while (tr[x].p != g) {
        int y = tr[x].p, z = tr[y].p;
        if (z != g)
            if ((x == tr[y].s[1]) ^ (y == tr[z].s[1])) rotate(x);
            else rotate(y);
        rotate(x);
    }

    if (!g) root = x;
}

int insert(int v) {
    int u = root, p = 0;
    while (u) p = u, u = tr[u].s[v > tr[u].v];
    u = ++idx;
    if (p) tr[p].s[v > tr[p].v] = u;
    tr[u].init(v, p);
    splay(u, 0);
    return u;
}

int get(int v) {
    int u = root, res;
    while (u) {
        if (tr[u].v >= v) res = u, u = tr[u].s[0];
        else u = tr[u].s[1];
    }

    return res;
}

int get_k(int k) {
    int u = root;
    while (u) {
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];
        else if (tr[tr[u].s[0]].size + 1 < k){
            k -= tr[tr[u].s[0]].size + 1;
            u = tr[u].s[1];
        } else return tr[u].v;
    }

    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    int L = insert(-INF), R = insert(INF);

    int tot = 0;
    while (n--) {
        char op[2];
        int k;
        scanf("%s%d", op, &k);
        if (op[0] == 'I') {
            if (k >= m) {
                insert(k - delta);
                tot++;
            }
        } else if (op[0] == 'A') delta += k;
        else if (op[0] == 'S') {
            delta -= k;
            R = get(m - delta);
            splay(R, 0), splay(L, R);
            tr[L].s[1] = 0;
            pushup(L), pushup(R);
        } else {
            if (tr[root].size - 2 < k) puts("-1");
            else printf("%d\n", get_k(tr[root].size - k) + delta);
        }
    }
    
    printf("%d\n", tot - (tr[root].size - 2));
    return 0; 
}