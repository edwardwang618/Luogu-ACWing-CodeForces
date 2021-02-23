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
        res ^= a[i];
    }

    cout << (res == 0 ? "No" : "Yes") << endl;

    return 0;
}