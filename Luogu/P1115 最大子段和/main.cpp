#include <iostream>
using namespace std;

int n;
int res = -0x3f3f3f3f, sum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum = max(x + sum, x);
        res = max(res, sum);
    }

    cout << res << endl;
    return 0;
}