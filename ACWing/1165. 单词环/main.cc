#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 26 * 26, M = 100010;
int n, V;
int h[N], e[M], w[M], ne[M], idx;
double dist[N];
int stk[N], top;
int cnt[N];
bool st[N];
unordered_set<int> s;

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool check(double mi) {
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0, sizeof dist);

    V = s.size();
    top = 0;

    for (int i = 0; i < N; i++) {
        if (h[i] == -1) continue;

        stk[top++] = i;
        st[i] = true;
    }

    int count = 0;
    while (top) {
        int t = stk[--top];
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[t] + w[i] - mi) {
                dist[j] = dist[t] + w[i] - mi;
                cnt[j] = cnt[t] + 1;

                if (cnt[j] >= V) return true;

                if (!st[j]) {
                    stk[top++] = j;
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    string str;
    while (scanf("%d", &n), n) {
        memset(h, -1, sizeof h);
        idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> str;
            int len = str.size();
            if (len >= 2) {
                int left = (str[0] - 'a') * 26 + str[1] - 'a';
                int right = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
                s.insert(left), s.insert(right);
                add(left, right, len);
            }
        }

        if (!check(0)) cout << "No solution" << endl;
        else {
            double l = 0, r = 1000;
            while (l + 1e-4 < r) {
                double mi = (l + r) / 2;
                if (check(mi)) l = mi;
                else r = mi;
            }

            printf("%lf\n", l);
        }
    }

    return 0;
}