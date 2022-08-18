#include <iostream>
#include <stack>
using namespace std;

const int N = 100010;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> stk;

    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.top() >= a[i]) stk.pop();
        cout << (stk.empty() ? -1 : stk.top()) << ' ';
        stk.push(a[i]);
    }

    return 0;
}