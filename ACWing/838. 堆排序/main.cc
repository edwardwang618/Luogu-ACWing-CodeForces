#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int h[N], s;

void down(int u) {
    while (u * 2 <= s) {
        int t = u;
        if (h[u * 2] < h[t]) t = u * 2;
        if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
        if (u != t) {
            swap(h[u], h[t]);
            u = t;
        } else break;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> h[i];
    s = n;

    for (int i = n / 2; i > 0; i--) down(i);

    while (m--) {
        cout << h[1] << ' ';
        h[1] = h[s--];
        down(1);
    }

    return 0;
}