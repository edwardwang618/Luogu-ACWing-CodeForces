#include <iostream>
using namespace std;

const int N = 100010;
int M;
int stk[N];
int top = 0;

void push(int x) {
    stk[top++] = x;
}

void pop() {
    top--;
}

bool empty() {
    return top == 0;
}

int query() {
    return stk[top - 1];
}

int main() {
    cin >> M;

    while (M--) {
        string op;
        cin >> op;
        int x;

        if (op == "push") {
            cin >> x; 
            push(x);
        } else if (op == "pop") pop();
        else if (op == "empty") cout << (empty() ? "YES" : "NO") << endl;
        else if (op == "query") cout << query() << endl;
    }

    return 0;
}