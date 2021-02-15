#include <iostream>
using namespace std;

const int N = 1000010;
int primes[N], res;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[res++] = i;
            for (int j = i + i; j <= n; j += i) st[j] = true;
        }
    }
}

int main() {
    int n;
    cin >> n;
    get_primes(n);

    cout << res << endl;

    return 0;
}