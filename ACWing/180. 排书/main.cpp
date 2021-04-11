#include <iostream>
#include <cstring>
using namespace std;

const int N = 18;
int n, a[N];
int w[5][N];

int f() {
    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i + 1] != a[i] + 1) cnt++;

    return (cnt + 2) / 3;
}

bool dfs(int depth, int max_depth) {
    if (depth + f() > max_depth) return false;

    if (f() == 0) return true;

    for (int len = 1; len <= n; len++)
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            for (int k = r + 1; k < n; k++) {
                memcpy(w[depth], a, sizeof a);
                int y = l;
                for (int x = r + 1; x <= k; x++)
                    a[y++] = w[depth][x];
                for (int x = l; x <= r; x++)
                    a[y++] = w[depth][x];

                if (dfs(depth + 1, max_depth)) 
                    return true;

                memcpy(a, w[depth], sizeof a);
            }
        }

    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        int depth = 0;
        while (depth < 5 && !dfs(0, depth)) depth++;
        
        if (depth >= 5) cout << "5 or more" << endl;
        else cout << depth << endl;
    }

    return 0;
}