#include <iostream>
using namespace std;

const int N = 1e5 + 10;
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
    if (px != py) p[px] = py;
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
        else if (op == 'Q') {
            if (find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }

    return 0;
}