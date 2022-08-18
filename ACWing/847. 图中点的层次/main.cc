#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
bool vis[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs() {
    if (n == 1) return 0;

    int res = 0;

    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        res++;

        int s = q.size();
        for (int i = 0; i < s; i++) {
            int cur = q.front();
            q.pop();
            for (int i = h[cur]; i != -1; i = ne[i]) {
                int j = e[i];
                if (j == n) return res;
                if (!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs() << endl;

    return 0;
}