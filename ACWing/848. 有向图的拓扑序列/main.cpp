#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int N = 100010;
int n, m;
int h[N], e[N], ne[N], idx;
int d[N];
bool vis[N];
vector<int> res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    queue<int> q;
    for (int i = 1; i <= n; i++) 
        if (!d[i]) {
            q.push(i);
            vis[i] = true;
        }

    while (!q.empty()) {
        int f = q.front();
        res.push_back(f);
        q.pop();
        for (int i = h[f]; i != -1; i = ne[i]) {
            int j = e[i];
            if (vis[j]) continue;

            d[j]--;
            if (!d[j]) {
                q.push(j);
                vis[j] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    topsort();

    if (res.size() < n) puts("-1");
    else for (int i = 0; i < n; i++) cout << res[i] << ' ';

    return 0;
}