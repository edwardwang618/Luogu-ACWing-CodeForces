#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int N = 100010;
// ph从下标映射到堆，hp从堆映射到下标
int h[N], ph[N], hp[N], s;

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    while (u * 2 <= s) {
        int t = u;
        if (h[u * 2] < h[t]) t = u * 2;
        if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
        if (u != t) {
            heap_swap(u, t);
            u = t;
        } else break;
    }
}

void up(int u) {
    while (u >> 1 && h[u >> 1] > h[u]) {
        heap_swap(u >> 1, u);
        u >>= 1;
    }
}

int main() {
    int n, m = 0;
    cin >> n;

    while (n--) {
        char op[10];
        int k, x;
        scanf("%s", op);
        if (!strcmp(op, "I")) {
            cin >> x;
            s++;

            m++;
            ph[m] = s;
            hp[s] = m;
            h[s] = x;
            up(s);
        } else if (!strcmp(op, "PM")) cout << h[1] << endl;
        else if (!strcmp(op, "DM")) {
            heap_swap(1, s);
            s--;
            down(1);
        } else if (!strcmp(op, "D")) {
            cin >> k;
            k = ph[k];
            heap_swap(k, s);
            s--;
            down(k), up(k);
        } else if (!strcmp(op, "C")) {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }

    return 0;
}