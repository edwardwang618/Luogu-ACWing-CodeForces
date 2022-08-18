#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

const int N = 110;

int f[N];

int sg(int x) {
    if (f[x] != -1) return f[x];

    unordered_set<int> set;
    for (int i = 0; i < x; i++) 
        for (int j = 0; j <= i; j++)
            set.insert(sg(i) ^ sg(j));

    for (int i = 0; ; i++) 
        if (!set.count(i)) return f[x] = i;
}

int main() {
    int n;
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