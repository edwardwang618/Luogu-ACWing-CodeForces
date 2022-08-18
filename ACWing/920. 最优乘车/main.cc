#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

const int N = 510;
int m, n;
bool g[N][N];
int stop[N];
bool st[N];

int bfs() {
    if (n == 1) return 0;
    
    queue<int> q;
    q.push(1);
    st[1] = true;

    int res = 0;
    while (q.size()) {
        res++;
        int s = q.size();
        for (int i = 0; i < s; i++) {
            int t = q.front();
            q.pop();

            for (int j = 1; j <= n; j++) 
                if (g[t][j] && !st[j]) {
                    if (j == n) return res;
                    q.push(j);
                    st[j] = true;
                }
        }
    }

    return -1;
}

int main() {
    cin >> m >> n;

    string line;
    getline(cin, line);
    while (m--) {
        getline(cin, line);
        stringstream ssin(line);
        int cnt = 0, p;
        while (ssin >> p) stop[cnt++] = p;
        for (int j = 0; j < cnt; j++)
            for (int k = j + 1; k < cnt; k++)
                g[stop[j]][stop[k]] = true;
    }

    int res = bfs();

    if (res == -1) cout << "NO" << endl;
    else cout << max(res - 1, 0) << endl;

    return 0;
}