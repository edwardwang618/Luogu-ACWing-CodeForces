#include <iostream>
using namespace std;

const int N = 20;

int n, m;
int p[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> p[i];

    int res = 0;
    for (int i = 1; i < 1 << m; i++) {
        int prod = 1, cnt = 0;
        for (int j = 0; j < m; j++)
            if (i >> j & 1) {
                cnt++;
                if ((long) prod * p[j] > n) {
                    prod = -1;
                    break;
                }

                prod *= p[j];
            }

        if (prod != -1) 
            if (cnt % 2) res += n / prod;
            else res -= n / prod;
    }

    cout << res << endl;

    return 0;
}