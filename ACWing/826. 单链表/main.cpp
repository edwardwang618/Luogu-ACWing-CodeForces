#include <iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}

void add(int k, int x) {
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx, idx++;
}

void remove(int k) {
    if (k == -1) head = ne[head];
    else ne[k] = ne[ne[k]];
}

int main() {
    int n;
    cin >> n;

    init();
    while (n--) {
        char op;
        int k, x;

        cin >> op;
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        } else if (op == 'I') {
            cin >> k >> x;
            add(k - 1, x);
        } else if (op == 'D') {
            cin >> k;
            remove(k - 1);
        }
    }

    while (head != -1) {
        cout << e[head] << ' ';
        head = ne[head];
    }

    return 0;
}