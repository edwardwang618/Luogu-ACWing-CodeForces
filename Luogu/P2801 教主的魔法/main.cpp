#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int N = 1e6 + 10, M = 1050;
int n, q, len;
int w[N], lazy[M];
vector<int> BQ[M];

int get(int i) {
    return i / len;
}

void init() {
    for (int i = 0; i < n; i++) BQ[get(i)].push_back(w[i]);
    for (int i = 0; i < n; i += len) sort(BQ[get(i)].begin(), BQ[get(i)].end());
}

void update(int u) {
    vector<int> &v = BQ[u];
    v.clear();
    for (int i = u * len; i < min(n, (u + 1) * len); i++)
        v.push_back(w[i]);

    sort(v.begin(), v.end());
}

void add(int l, int r, int v) {
    if (get(l) == get(r)) {
        for (int i = l; i <= r; i++) w[i] += v;
        update(get(l));
    } else {
        int i = l, j = r;
        while (get(i) == get(l)) w[i++] += v;
        update(get(l));
        while (get(j) == get(r)) w[j--] += v;
        update(get(r));
        for (int k = get(i); k <= get(j); k++) lazy[k] += v;
    }
}

int query(int l, int r, int v) {
    int res = 0;
    if (get(l) == get(r)) {
        for (int i = l; i <= r; i++)
            if (w[i] + lazy[get(l)] >= v) res++;
    } else {
        int i = l, j = r;
        while (get(i) == get(l)) {
            if (w[i] + lazy[get(i)] >= v) res++;
            i++;
        }
        while (get(j) == get(r)) {
            if (w[j] + lazy[get(j)] >= v) res++;
            j--;
        }
        for (int k = get(i); k <= get(j); k++) {
            vector<int> &vec = BQ[k];
            int l = 0, r = vec.size() - 1;
            while (l < r) {
                int mid = l + (r - l >> 1);
                if (vec[mid] + lazy[k] >= v) r = mid;
                else l = mid + 1;
            }

            if (vec[l] + lazy[k] >= v) res += vec.size() - l;
        }
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &q);
    len = sqrt(n);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    init();

    while (q--) {
        char op[2];
        int l, r, v;
        scanf("%s%d%d%d", op, &l, &r, &v);
        if (op[0] == 'A') printf("%d\n", query(l - 1, r - 1, v));
        else add(l - 1, r - 1, v);
    }

    return 0;
}