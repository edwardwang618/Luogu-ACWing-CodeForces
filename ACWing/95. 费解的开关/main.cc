#include <iostream>
#include <cstring>
using namespace std;

const int N = 5;
char g[N][N], bg[N][N];

void flip(char& x) {
    x = x == '0' ? '1' : '0';
}

void click(int x, int y) {
    flip(g[x][y]);
    if (x - 1 >= 0) flip(g[x - 1][y]);
    if (x + 1 < 5) flip(g[x + 1][y]);
    if (y - 1 >= 0) flip(g[x][y - 1]);
    if (y + 1 < 5) flip(g[x][y + 1]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 5; i++) scanf("%s", bg[i]);

        int res = 10;
        for (int op = 0; op < 32; op++) {
            int cnt = 0;
            memcpy(g, bg, sizeof g);
            for (int i = 0; i < 5; i++) 
                if (op >> i & 1) {
                    click(0, i);
                    cnt++;
                }
            
            for (int i = 1; i < 5; i++)
                for (int j = 0; j < 5; j++)
                    if (g[i - 1][j] == '0') {
                        click(i, j);
                        cnt++;
                    }

            bool success = true;
            for (int i = 0; i < 5; i++)
                if (g[4][i] == '0') {
                    success = false;
                    break;
                }
            
            if (success) res = min(res, cnt);
        }

        printf("%d\n", res > 6 ? -1 : res);
    }

    return 0;
}