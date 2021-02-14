#include <iostream>
#include <cstring>
using namespace std;

void dfs(int i, int res[], int n, bool used[], bool diag[], bool udiag[]) {
    if (i == n) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (res[j] == k) cout << 'Q';
                else cout << '.';
            }
            cout << endl;
        }

        cout << endl;
        return;
    }

    for (int j = 0; j < n; j++) {
        if (used[j] || diag[i - j + n - 1] || udiag[i + j]) continue;
        used[j] = diag[i - j + n - 1] = udiag[i + j] = true;
        res[i] = j;
        dfs(i + 1, res, n, used, diag, udiag);
        used[j] = diag[i - j + n - 1] = udiag[i + j] = false;
    }
}

int main() {
    int n;
    cin >> n;

    int res[n];
    bool used[n], diag[2 * n - 1], udiag[2 * n - 1];
    memset(used, false, sizeof used);
    memset(diag, false, sizeof diag);
    memset(udiag, false, sizeof udiag);

    dfs(0, res, n, used, diag, udiag);

    return 0;
}