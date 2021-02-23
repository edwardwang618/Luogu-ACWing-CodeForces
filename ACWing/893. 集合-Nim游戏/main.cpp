#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 110, M = 10010;

int k, n;
int s[N], f[M];

int sg(int x) {
    if (f[x] != -1) return f[x];

    unordered_set<int> set;
    for (int i = 0; i < k; i++) {
        if (x >= s[i]) set.insert(sg(x - s[i]));
    }

    for (int i = 0; ; i++)
        if (!set.count(i)) return f[x] = i;
}

int main() {
    cin >> k;
    for (int i = 0; i < k; i++) cin >> s[i];
    cin >> n;

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    cout << (res != 0 ? "Yes" : "No") << endl;

    return 0;
}