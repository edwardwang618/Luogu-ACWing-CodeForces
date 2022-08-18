#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int> > PII;

const int R = 55, C = 55, d[] = {1, 0, -1, 0, 1};
int r, c;
int h[R][C];
bool st[R][C];

int get_vol() {
    memset(st, 0, sizeof st);
    
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    for (int i = 1; i <= r; i++) {
        heap.push({h[i][1], {i, 1}}), heap.push({h[i][c], {i, c}});
        st[i][1] = st[i][c] = true;
    }
    for (int i = 1; i <= c; i++) {
        heap.push({h[1][i], {1, i}}), heap.push({h[r][i], {r, i}});
        st[1][i] = st[r][i] = true;
    }

    int res = 0;
    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int hei = t.first, x = t.second.first, y = t.second.second;
        
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i], ny = y + d[i + 1];
            if (!st[nx][ny] && 1 <= nx && nx <= r && 1 <= ny && ny <= c) {
                res += max(0, hei - h[nx][ny]);
                heap.push({max(hei, h[nx][ny]), {nx, ny}});
                st[nx][ny] = true;
            }
        }
    }
    
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> r >> c;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> h[i][j];

        printf("Case #%d: %d\n", t, get_vol());
    }

    return 0;
}