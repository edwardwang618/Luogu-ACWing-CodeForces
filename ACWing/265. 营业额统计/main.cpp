#include <iostream>
#include <cstring>
using namespace std;

const int N = 33010, INF = 1e8;
int n;
struct Node {
    int son[2];
    int key, val;
}tr[N];
int root, idx;

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    return idx;
}

void rotate(int &p, int d) {
    int q = tr[p].son[d ^ 1];
    tr[p].son[d ^ 1] = tr[q].son[d];
    tr[q].son[d] = p;
    p = q;
}

void insert(int &p, int key) {
    if (!p) p = get_node(key);
    else if (key < tr[p].key) {
        insert(tr[p].son[0], key);
        if (tr[tr[p].son[0]].val > tr[p].val) rotate(p, 1);
    } else if (key > tr[p].key) {
        insert(tr[p].son[1], key);
        if (tr[tr[p].son[1]].val > tr[p].val) rotate(p, 0);
    }
}

int get_prev(int p, int key) {
    if (!p) return -INF;
    if (tr[p].key > key) return get_prev(tr[p].son[0], key);
    return max(tr[p].key, get_prev(tr[p].son[1], key));
}

int get_next(int p, int key) {
    if (!p) return INF;
    if (tr[p].key < key) return get_next(tr[p].son[1], key);
    return min(tr[p].key, get_next(tr[p].son[0], key));
}

int main() {
    scanf("%d", &n);
    long res = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (i == 1) res += x;
        else res += min(x - get_prev(root, x), get_next(root, x) - x);
        insert(root, x);
    }

    printf("%ld\n", res);

    return 0;
}