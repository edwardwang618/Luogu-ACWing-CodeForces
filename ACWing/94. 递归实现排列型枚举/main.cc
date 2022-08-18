#include <iostream>
using namespace std;

const int N = 10;
int n;
int a[N];
bool st[N];

void dfs(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (st[i]) continue;

        a[idx] = i;
        st[i] = true;
        dfs(idx + 1);
        st[i] = false;
    }
}

int main() {
    cin >> n;
    dfs(0);

    return 0;
}