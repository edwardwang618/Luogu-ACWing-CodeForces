#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stk;
    int x = 0;
    char ch;
    while (scanf("%c", &ch), ch != '@') {
        if (isdigit(ch)) x = x * 10 + ch - '0';
        else if (ch == '.') {
            stk.push(x);
            x = 0;
        } else {
            int b = stk.top(); stk.pop();
            int a = stk.top(); stk.pop();
            switch (ch) {
                case '+': stk.push(a + b); break;
                case '-': stk.push(a - b); break;
                case '*': stk.push(a * b); break;
                case '/': stk.push(a / b); break;
            }
        }
    }

    cout << stk.top() << endl;

    return 0;
}