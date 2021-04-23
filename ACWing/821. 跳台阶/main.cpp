#include <iostream>
using namespace std;

const int N = 20;
int f[N];

int main() {
    int n;
    cin >> n;

    f[1] = 1, f[2] = 2;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];

    cout << f[n] << endl;

    return 0;
}