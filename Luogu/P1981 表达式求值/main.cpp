#include <iostream>
#include <stack>
using namespace std;

const int mod = 10000;

void calc(stack<int>& stk, stack<char>& ops) {
    int n2 = stk.top(); stk.pop();
    int n1 = stk.top(); stk.pop();
    char ch = ops.top(); ops.pop();
    if (ch == '+') stk.push((n1 + n2) % mod);
    else stk.push(n1 * n2 % mod);
}

int main() {
    string s;
    cin >> s;

    stack<int> stk;
    stack<char> ops;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (isdigit(ch)) {
            int j = i;
            while (j < s.size() && isdigit(s[j])) j++;
            int x = stoi(s.substr(i, j - i)) % mod;
            stk.push(x);
            i = j - 1;
        } else if (ch == '*') {
            while (ops.size() && ops.top() == '*') {
                calc(stk, ops);
            }

            ops.push(ch);
        } else if (ch == '+') {
            while (ops.size()) {
                calc(stk, ops);
            }

            ops.push(ch);
        }
    }

    while (ops.size()) calc(stk, ops);

    cout << stk.top() << endl;

    return 0;
}