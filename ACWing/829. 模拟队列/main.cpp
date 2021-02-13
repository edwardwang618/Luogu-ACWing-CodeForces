#include <iostream>
using namespace std;

const int N = 100010;
int q[N];
int hh, tt;

void push(int x) {
    q[tt++] = x;
}

void pop() {
    hh++;
}

bool empty() {
    return hh == tt;
}

int query() {
    return q[hh];
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "empty")
            cout << (empty() ? "YES" : "NO") << endl;
        else if (op == "query") 
            cout << query() << endl;
        else if (op == "pop") pop();
    }

    return 0;
}