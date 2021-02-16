#include <iostream>
using namespace std;

long euler(int x) {
    long res = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            res = res * (i - 1) / i;
            while (x % i == 0) x /= i;
        }
    }

    if (x >= 2) res = res * (x - 1) / x;
    return res;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int a;
        cin >> a;
        cout << euler(a) << endl;
    }

    return 0;
}