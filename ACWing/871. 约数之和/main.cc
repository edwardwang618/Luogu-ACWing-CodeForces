#include <iostream>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
unordered_map<int, int> map;

void divide(int n) {
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            int c = 0;
            while (n % i == 0) {
                c++;
                n /= i;
            }
            
            map[i] += c;
        }
    }

    if (n >= 2) map[n]++;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        divide(x);
    }

    long res = 1;
    for (auto pa : map) {
        int p = pa.first, a = pa.second;
        long t = 1;
        while (a--) t = (t * p + 1) % MOD;
        res = res * t % MOD;
    }

    cout << res << endl;

    return 0;
}