#include <iostream>
using namespace std;

const int N = 100010;
int p[N];

void init(int n) {
    for (int i = 1; i <= n; i++) p[i] = i;
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;

    p[px] = py;
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n);

    while (m--) {
        char op;
        int a, b;
        cin >> op;
        cin >> a >> b;

        if (op == 'M') merge(a, b);
        else if (op == 'Q') cout << (find(a) == find(b) ? "Yes" : "No") << endl;
    }

    return 0;
}