#include <iostream>
#include <cstring>

using namespace std;

const int N = 26;
int n, m;
int d[N][N];
bool st[N];

int check() {
    for (int i = 0; i < n; i++)
        if (d[i][i]) return -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (!d[i][j] && !d[j][i])
                return 0;

    return 1;
}

char get() {
    for (int i = 0; i < n; i++) {
        if (st[i]) continue;
        bool found = false;
        for (int j = 0; j < n; j++)
            if (!st[j] && d[j][i]) {
                found = true;
                break;
            }

        if (!found) {
            st[i] = true;
            return 'A' + i;
        }
    }

    return 0;
}

int main() {
    while (cin >> n >> m, n || m) {
        int type = 0, t;
        memset(d, 0, sizeof d);
        for (int i = 1; i <= m; i++) {
            char str[5];
            cin >> str;
            int a = str[0] - 'A', b = str[2] - 'A';
            if (!type) {
                d[a][b] = 1;
                for (int x = 0; x < n; x++) {
                    if (d[x][a]) d[x][b] = 1;
                    if (d[b][x]) d[a][x] = 1;
                    for (int y = 0; y < n; y++)
                        if (d[x][a] & d[b][y])
                            d[x][y] = 1;
                }
                    
                type = check();
                if (type) t = i;
            }
        }

        if (type == -1) printf("Inconsistency found after %d relations.\n", t);
        else if (type == 0) printf("Sorted sequence cannot be determined.\n");
        else {
            memset(st, 0, sizeof st);
            printf("Sorted sequence determined after %d relations: ", t);
            for (int i = 0; i < n; i++)
                printf("%c", get());
            printf(".\n");
        }
    }

    return 0;
}