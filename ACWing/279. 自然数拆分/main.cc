#include <iostream>
#include <cstring>
using namespace std;

const int N = 4010;
const long MOD = 2147483648;
int n;
long f[N];

int main() {
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % MOD;

    cout << f[n] - 1 << endl;

    return 0;
}