#include <iostream>
using namespace std;

const int N = 3e6 + 10;
int n;
int stk[N], top;
int a[N], res[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        while(top && a[stk[top - 1]] < a[i]) {
            res[stk[top - 1]] = i;
            top--;
        }

        stk[top++] = i;
    }

    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << endl;

    return 0;
}