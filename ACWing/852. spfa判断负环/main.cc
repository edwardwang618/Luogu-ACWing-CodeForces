#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 100010;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() {
    stack<int> stk;
    for (int i = 1; i <= n; i++) {
        stk.push(i);
        st[i] = true;
    }

    while (stk.size()) {
        int t = stk.top();
        stk.pop();

        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;

                if (!st[j]) {
                    stk.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << (spfa() ? "Yes" : "No") << endl;

    return 0;
}