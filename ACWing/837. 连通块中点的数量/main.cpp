#include <iostream>
using namespace std;

const int N = 100010;
int p[N], s[N];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        s[i] = 1;
    }
}

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return;
    p[px] = py;
    s[py] += s[px];
}

int main() {
    int n, m;
    cin >> n >> m;

    init(n);
    while (m--) {
        char op[2];
        int x, y;
        cin >> op;
        if (op[0] == 'C') {
            cin >> x >> y;
            merge(x, y);
        } else if (op[0] == 'Q') {
            if (op[1] == '1') {
                cin >> x >> y;
                cout << (find(x) == find(y) ? "Yes" : "No") << endl;
            } else if (op[1] == '2') {
                cin >> x;
                cout << s[find(x)] << endl;
            }
        }
    }

    return 0;
}