#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
int n;
int p[N];
vector<pair<int, int>> a;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    while (cin >> n) {
        int res = 0, maxd = 0;
        a.clear();
        for (int i = 0; i < n; i++) {
            int v, d;
            scanf("%d%d", &v, &d);
            a.push_back({v, d});
            maxd = max(maxd, d);
        }

        for (int i = 0; i <= maxd; i++) p[i] = i;
        sort(a.begin(), a.end(), greater<pair<int, int>>());
        for (int i = 0; i < a.size(); i++) {
            int v = a[i].first, d = a[i].second;
            int date = find(d);
            if (date) {
                res += v;
                p[date] = date - 1;
            }
        }

        printf("%d\n", res);
    }

    return 0;
}