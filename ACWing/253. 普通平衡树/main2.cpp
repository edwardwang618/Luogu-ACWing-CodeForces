#include <iostream>

using namespace std;

const int N = 1e5 + 10, INF = 1e8;
int n;

struct Node {
    int l, r;
    int key, val;
    int cnt, size;
} tr[N];
int root, idx;
int x, y, z;

int get_node(int key) {
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].size = tr[idx].cnt = 1;
    return idx;
}

void push_up(int p) {
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

void split(int p, int key, int &x, int &y) {
    if (!p) x = y = 0;
    else {
        if (tr[p].key <= key) {
            x = p;
            split(tr[p].r, key, tr[p].r, y);
        } else {
            y = p;
            split(tr[p].l, key, x, tr[p].l);
        }

        // 不能更新null节点的size
        push_up(p);
    }
}

int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (tr[x].val > tr[y].val) {
        tr[x].r = merge(tr[x].r, y);
        push_up(x);
        return x;
    } else {
        tr[y].l = merge(x, tr[y].l);
        push_up(y);
        return y;
    }
}

void insert(int key) {
    split(root, key, x, z);
    split(x, key - 1, x, y);
    if (!y) y = get_node(key);
    else {
        tr[y].cnt++;
        tr[y].size++;
    }

    root = merge(merge(x, y), z);
}

void remove(int key) {
    split(root, key, x, z);
    split(x, key - 1, x, y);
    if (y) {
        tr[y].cnt--;
        tr[y].size--;
    }

    if (!tr[y].cnt) y = 0;
    root = merge(merge(x, y), z);
}

int get_rank_by_key(int key) {
    split(root, key - 1, x, y);
    int rank = tr[x].size + 1;
    root = merge(x, y);
    return rank;
}

int get_key_by_rank(int rank) {
    int p = root;
    while (p) {
        if (tr[tr[p].l].size >= rank)
            p = tr[p].l;
        else if (tr[tr[p].l].size + tr[p].cnt < rank) {
            rank -= tr[tr[p].l].size + tr[p].cnt;
            p = tr[p].r;
        } else return tr[p].key;
    }

    return INF;
}

int get_prev(int key) {
    split(root, key - 1, x, y);
    int p = x;
    while (tr[p].r) p = tr[p].r;
    root = merge(x, y);
    return tr[p].key;
}

int get_next(int key) {
    split(root, key, x, y);
    int p = y;
    while (tr[p].l) p = tr[p].l;
    root = merge(x, y);
    return tr[p].key;
}

int main() {
    scanf("%d", &n);
    while (n--) {
        int opt, a;
        scanf("%d%d", &opt, &a);
        if (opt == 1) insert(a);
        else if (opt == 2) remove(a);
        else if (opt == 3) printf("%d\n", get_rank_by_key(a));
        else if (opt == 4) printf("%d\n", get_key_by_rank(a));
        else if (opt == 5) printf("%d\n", get_prev(a));
        else if (opt == 6) printf("%d\n", get_next(a));
    }

    return 0;
}