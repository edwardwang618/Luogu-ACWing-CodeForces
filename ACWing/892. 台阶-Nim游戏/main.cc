#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

int main() {
    int n;
    cin >> n;

    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) res ^= a[i];
    }

    cout << (res != 0 ? "Yes" : "No") << endl;

    return 0;
}